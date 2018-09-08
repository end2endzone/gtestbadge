/**********************************************************************************
 * MIT License
 * 
 * Copyright (c) 2018 Antoine Beauchamp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdio.h>

//for putenv()
#ifndef _WIN32
#include <unistd.h>
#endif
#include <stdlib.h>
#include <string.h>

#include <gtest/gtest.h>

#include "rapidassist/gtesthelp.h"
#include "rapidassist/filesystem.h"
#include "rapidassist/cli.h"
#include "rapidassist/environment.h"

#include "gtestbadge/BadgeEventListener.h"

using namespace ra::gtesthelp;

//command line arguments definition
std::string output_badge;
int num_test_failures = 0;
int warning_ratio_percent = 0;

enum ERROR_CODES
{
  ERROR_SUCCESS,
  ERROR_MISSING_ARGUMENT_OUTPUT_BADGE,
  ERROR_MISSING_ARGUMENT_NUM_TEST_FAILURES,
  ERROR_MISSING_ARGUMENT_WARNING_RATIO_PERCENT,
  ERROR_BADGE_SAVE_UNKNOWN_ERROR,
};

int main(int argc, char **argv)
{
  //print arguments
  for(int i=0; i<argc; i++)
  {
    printf("[%d]=%s\n", i, argv[i]);
  }

  ::testing::GTEST_FLAG(filter) = "*";
  ::testing::InitGoogleTest(&argc, argv);

  //reads arguments for tests
  if (!ra::cli::parseArgument("output_badge", output_badge, argc, argv))
  {
    printf("Missing argument: --%s\n", "output_badge");
    return ERROR_MISSING_ARGUMENT_OUTPUT_BADGE;
  }

  if (!ra::cli::parseArgument("num_test_failures", num_test_failures, argc, argv))
  {
    printf("Missing argument: --%s\n", "num_test_failures");
    return ERROR_MISSING_ARGUMENT_NUM_TEST_FAILURES;
  }

  if (!ra::cli::parseArgument("warning_ratio_percent", warning_ratio_percent, argc, argv))
  {
    printf("Missing argument: --%s\n", "warning_ratio_percent");
    return ERROR_MISSING_ARGUMENT_WARNING_RATIO_PERCENT;
  }
  double ratio = double(warning_ratio_percent)/100.0;

  //detect forced icons
  std::string forced_icon;
  int tmp = 0;
  if (ra::cli::parseArgument("appveyor", tmp, argc, argv))
  {
#ifdef _WIN32
    _putenv("APPVEYOR=True");
#else
    putenv("APPVEYOR=True");
#endif
    forced_icon = "AppVeyor";
  }
  else if (ra::cli::parseArgument("travis", tmp, argc, argv))
  {
#ifdef _WIN32
    _putenv("TRAVIS=true");
#else
    putenv("TRAVIS=true");
#endif
    forced_icon = "Travis CI";
  }

  //print arguments
  printf("Generating badge file '%s'.\n", output_badge.c_str());
  printf("Warning ratio set to %.2f.\n", ratio);
  printf("Forcing %d test(s) out of 10 to fail.\n", num_test_failures);
  if (!forced_icon.empty())
  {
    printf("CI service: %s.\n", forced_icon.c_str());
  }

  // Adds a BadgeEventListener instance to the end of the test event listener list, 
  // **after** the default text output printer and the default XML report generator.
  // Note: the insert order is important.
  ::testing::TestEventListeners & listeners = ::testing::UnitTest::GetInstance()->listeners();

  //Disable default test listener to prevent 
  listeners.Release(listeners.default_result_printer());
  
  // Create and register a new BadgeEventListener
  BadgeEventListener * bel = new BadgeEventListener();
  bel->setOutputFilename(output_badge.c_str());
  bel->setWarningRatio(ratio);
  listeners.Append(bel); //Google Test assumes the ownership of the listener (i.e. it will delete the listener when the test program finishes).

  printf("RUN_ALL_TESTS()\n");

  // Find and run all tests
  int wResult = RUN_ALL_TESTS();

  // Test badge creation result
  if (!bel->getSuccess())
  {
    printf("ERROR: Failed saving badge to file '%s'.\n", bel->getOutputFilename().c_str());
    return ERROR_BADGE_SAVE_UNKNOWN_ERROR;
  }

  printf("done.\n");

  //always a success disregarding the forced number of failed tests.
  return 0; // returns 0 if all the tests are successful, or 1 otherwise
}
