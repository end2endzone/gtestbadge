#include "rapid.h"

#include <gtest/gtest.h>

int strReplace(std::string & iString, const char * iOldValue, const char * iNewValue)
{
  std::string tmpOldValue = iOldValue;
  std::string tmpNewValue = iNewValue;

  int numOccurance = 0;

  if (tmpOldValue.size() > 0)
  {
    size_t startPos = 0;    
    size_t findPos = std::string::npos;
    do
    {
      findPos = iString.find(tmpOldValue, startPos);
      if (findPos != std::string::npos)
      {
        iString.replace(findPos, tmpOldValue.length(), tmpNewValue);
        startPos = findPos + tmpNewValue.length();
        numOccurance++;
      }
    }
    while (findPos != -1);
  }
  return numOccurance;
}

int strReplace(std::string & iString, const std::string & iOldValue, const std::string & iNewValue)
{
  return strReplace(iString, iOldValue.c_str(), iNewValue.c_str());
}

std::string toString(const int & value)
{
  #pragma warning( push )
  #pragma warning( disable: 4996 ) //warning C4996: 'itoa': The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: _itoa. See online help for details.
  char tmp[1024];
  std::string str = itoa(value, tmp, 10);
  #pragma warning( pop )
  return str;
}

std::string getTestSuiteName()
{
  std::string name = ::testing::UnitTest::GetInstance()->current_test_info()->test_case_name();
  return name;
}

std::string getTestCaseName()
{
  std::string name = ::testing::UnitTest::GetInstance()->current_test_info()->name();
  return name;
}

std::string getTestQualifiedName()
{
  const char * testSuiteName = ::testing::UnitTest::GetInstance()->current_test_info()->test_case_name();
  const char * testCaseName = ::testing::UnitTest::GetInstance()->current_test_info()->name();

  std::string name;
  name.append(testSuiteName);
  name.append(".");
  name.append(testCaseName);

  return name;
}
