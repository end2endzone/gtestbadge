#ifndef RAPID_H
#define RAPID_H

#include <string>

int strReplace(std::string & iString, const char * iOldValue, const char * iNewValue);
int strReplace(std::string & iString, const std::string & iOldValue, const std::string & iNewValue);
std::string toString(const int & value);

std::string getTestSuiteName();
std::string getTestCaseName();
std::string getTestQualifiedName();

#endif //RAPID_H