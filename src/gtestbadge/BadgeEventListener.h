#include <stdio.h>
#include <iostream>

#include <gtest/gtest.h>
#include <string>

using namespace testing;

class BadgeEventListener : public ::testing::TestEventListener
{
public:
  BadgeEventListener();
  virtual ~BadgeEventListener();

  virtual void OnTestProgramStart(const UnitTest& unit_test);
  virtual void OnTestIterationStart(const UnitTest& unit_test, int iteration);
  virtual void OnEnvironmentsSetUpStart(const UnitTest& unit_test);
  virtual void OnEnvironmentsSetUpEnd(const UnitTest& unit_test);
  virtual void OnTestCaseStart(const TestCase& test_case);
  virtual void OnTestStart(const TestInfo& test_info);
  virtual void OnTestPartResult(const TestPartResult& test_part_result);
  virtual void OnTestEnd(const TestInfo& test_info);
  virtual void OnTestCaseEnd(const TestCase& test_case);
  virtual void OnEnvironmentsTearDownStart(const UnitTest& unit_test);
  virtual void OnEnvironmentsTearDownEnd(const UnitTest& unit_test);
  virtual void OnTestIterationEnd(const UnitTest& unit_test, int iteration);
  virtual void OnTestProgramEnd(const UnitTest& unit_test);

  void setOutputFilename(const std::string & iFilename);

  enum SYSTEM_ICON
  {
    ICON_NONE,
    ICON_APPVEYOR,
    ICON_TRAVIS,
  };
  static bool generateBadge(const std::string & iFilename, int success, int failures, int disabled, const SYSTEM_ICON & iIcon);

private:
  std::string mOutputFilename;
};
