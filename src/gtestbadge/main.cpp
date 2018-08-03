#include <stdio.h>
#include <iostream>

#include <gtest/gtest.h>

#include "BadgeEventListener.h"

int main(int argc, char **argv)
{
  //define default values for xml output report
#ifdef NDEBUG
  ::testing::GTEST_FLAG(output) = "xml:gtestbadge.release.xml";
#else
  ::testing::GTEST_FLAG(output) = "xml:gtestbadge.debug.xml";
#endif

  ::testing::GTEST_FLAG(filter) = "*";
  ::testing::InitGoogleTest(&argc, argv);

  // Create Badge event listener
  BadgeEventListener * badge = new BadgeEventListener();
  badge->setOutputFilename("mybadge.svg");

  // Register event listener
  ::testing::UnitTest& unitTest = *::testing::UnitTest::GetInstance() ; 
  ::testing::TestEventListeners& listeners = unitTest.listeners() ; 
  listeners.Append( badge ) ; //Google Test takes the ownership.

  int wResult = RUN_ALL_TESTS(); //Find and run all tests

  //tests
  BadgeEventListener::generateBadge("tests_passed_51_appveyor.generated.svg", 51, 0, 0, BadgeEventListener::ICON_APPVEYOR);
  BadgeEventListener::generateBadge("tests_passed_51.generated.svg", 51, 0, 0, BadgeEventListener::ICON_NONE);

  return wResult; // returns 0 if all the tests are successful, or 1 otherwise
}
