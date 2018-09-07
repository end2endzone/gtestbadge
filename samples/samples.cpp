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

#include "gtestbadge/Badge.h"
#include "gtestbadge/BadgeEventListener.h"
#include "rapidassist/filesystem.h"

bool processBadge(const char * filename, int success, int failures)
{
  std::string sample_dir = SAMPLES_DIRECTORY;
  std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + filename;

  printf("Generating sample badge '%s'\n", filepath.c_str());
  if ( ! BadgeEventListener::generateBadge(filepath.c_str(), success, failures, 0, BadgeEventListener::ICON_NONE, BadgeEventListener::DEFAULT_WARNING_RATIO))
  {
    return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  std::string sample_dir = SAMPLES_DIRECTORY;

  //create 'samples' directory
  if (!ra::filesystem::createFolder(sample_dir.c_str()))
  {
    return __LINE__;
  }

  //passed
  if (!processBadge("sample_passed.svg", 56, 0))
  {
    return __LINE__;
  }

  //warning
  if (!processBadge("sample_warning.svg", 56, 4))
  {
    return __LINE__;
  }

  //error
  if (!processBadge("sample_error.svg", 56, 17))
  {
    return __LINE__;
  }

  //custom
  {
    Badge b;
    b.setLeftText("Progress");
    b.setRightBackgroundColor("#00a2e8");
    b.setRightText("92%");
    std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + "sample_custom_progress.svg";
    printf("Generating sample badge '%s'\n", filepath.c_str());
    bool saved = b.save(filepath.c_str());
    if (!saved)
    {
      return __LINE__;
    }
  }

  return 0;
}
