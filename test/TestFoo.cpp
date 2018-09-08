#include "TestFoo.h"
#include "rapidassist/gtesthelp.h"

extern int num_test_failures;

void TestFoo::SetUp()
{
}
void TestFoo::TearDown()
{
}

bool isMockTestSuccess(const std::string & iTestCaseName)
{
  //find the test number
  std::string test_number_str = iTestCaseName;
  ra::strings::strReplace(test_number_str, "test", "");

  //itoa
  int test_number = 0;
  const char * nextchar = test_number_str.c_str();
  while (nextchar[0] >= '0' && nextchar[0] <= '9')
  {
    test_number = 10 * test_number + nextchar[0] - '0';
    nextchar++; //next character
  }

  if (test_number <= num_test_failures)
    return false; //fails the test

  return true; //success
}

TEST_F(TestFoo, test01)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test02)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test03)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test04)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test05)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test06)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test07)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test08)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test09)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
TEST_F(TestFoo, test10)
{
  bool success = isMockTestSuccess(ra::gtesthelp::getTestCaseName());
  ASSERT_TRUE(success);
}
