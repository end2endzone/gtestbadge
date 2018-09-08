#include "TestSystem.h"
#include "rapidassist/gtesthelp.h"
#include "rapidassist/filesystem.h"
#include <cstdlib> //for system()

void TestSystem::SetUp()
{
}
void TestSystem::TearDown()
{
}

bool isRightTextBadge(const std::string & path, const std::string & text)
{
  std::string pattern = std::string(">") + text + "</text>";

  int tmpLine = 0;
  int tmpColumn = 0;
  bool found = ra::gtesthelp::findInFile(path.c_str(), pattern.c_str(), tmpLine, tmpColumn);
  return found;
}

bool isGreenBadge(const std::string & path)
{
  int tmpLine = 0;
  int tmpColumn = 0;
  bool found = ra::gtesthelp::findInFile(path.c_str(), "fill=\"#4c1\"", tmpLine, tmpColumn);
  return found;
}

bool isWarningBadge(const std::string & path)
{
  int tmpLine = 0;
  int tmpColumn = 0;
  bool found = ra::gtesthelp::findInFile(path.c_str(), "fill=\"#fe7d37\"", tmpLine, tmpColumn);
  return found;
}

bool isFailedBadge(const std::string & path)
{
  int tmpLine = 0;
  int tmpColumn = 0;
  bool found = ra::gtesthelp::findInFile(path.c_str(), "fill=\"#e05d44\"", tmpLine, tmpColumn);
  return found;
}

///<summary>Finds the path of 'gtestbadge_subtests' executable.</summary>
std::string getSubtestExecutablePath()
{
  //Build the filename
  std::string exeFilename = "gtestbadge_subtests";
  if (ra::gtesthelp::isDebugCode())
    exeFilename.append("-d");
#ifdef _WIN32
  exeFilename.append(".exe");
#endif

  //validate sub test file must exists
  
  //try local current directory
  if (ra::filesystem::fileExists(exeFilename.c_str()))
  {
    return exeFilename;
  }

  //try ${CMAKE_CURRENT_BINARY_DIR} directory
  std::string testfile;
  testfile.append("..");
  testfile.append(ra::filesystem::getPathSeparatorStr());
  testfile.append("bin");
#ifdef _WIN32
#ifdef NDEBUG
  testfile.append(ra::filesystem::getPathSeparatorStr());
  testfile.append("Release");
#else
  testfile.append(ra::filesystem::getPathSeparatorStr());
  testfile.append("Debug");
#endif //NDEBUG
#endif //_WIN32
  testfile.append(ra::filesystem::getPathSeparatorStr());
  testfile.append(exeFilename);
  if (ra::filesystem::fileExists(testfile.c_str()))
  {
    return testfile;
  }

  return std::string(); //failed locating gtestbadge_subtests executable
}

///<summary>Build a command line accepted by 'gtestbadge_subtests' executable.</summary>
std::string getSystemTestCommandLine(const std::string & badge_filename, int num_test_failures, int warning_ratio_percent)
{
  std::string execPath = getSubtestExecutablePath();
  
  if (!execPath.empty())
  {
    //build the command line
    std::string cmdline;
#ifndef _WIN32
    cmdline.append("./");
#endif
    cmdline.append(execPath);
    cmdline << " --output_badge=" << badge_filename << " --num_test_failures=" << num_test_failures << " --warning_ratio_percent=" << warning_ratio_percent;
    return cmdline;
  }

  return std::string(); //failed locating gtestbadge_subtests executable
}

TEST_F(TestSystem, testAllPassed)
{
  std::string badgeFilename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  std::string cmdline = getSystemTestCommandLine(badgeFilename, 0, 20);
  
  //run subtest command
  printf("exec: %s\n", cmdline.c_str());
  int wResult = system(cmdline.c_str());

  //assert success
  ASSERT_EQ(0, wResult);

  //assert badge content
  ASSERT_TRUE(ra::filesystem::fileExists(badgeFilename.c_str()));
  ASSERT_TRUE(isRightTextBadge(badgeFilename, "10 passed"));
  ASSERT_TRUE(isGreenBadge(badgeFilename));
}

TEST_F(TestSystem, testCiAutodetectAppVeyor)
{
  std::string badgeFilename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  std::string cmdline = getSystemTestCommandLine(badgeFilename, 0, 20);
  
  cmdline.append(" --appveyor");

  //run subtest command
  printf("exec: %s\n", cmdline.c_str());
  int wResult = system(cmdline.c_str());

  //assert success
  ASSERT_EQ(0, wResult);

  //assert badge content
  ASSERT_TRUE(ra::filesystem::fileExists(badgeFilename.c_str()));
  ASSERT_TRUE(isRightTextBadge(badgeFilename, "10 passed"));
  ASSERT_TRUE(isGreenBadge(badgeFilename));
}

TEST_F(TestSystem, testCiAutodetectTravis)
{
  std::string badgeFilename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  std::string cmdline = getSystemTestCommandLine(badgeFilename, 0, 20);
  
  cmdline.append(" --travis");

  //run subtest command
  printf("exec: %s\n", cmdline.c_str());
  int wResult = system(cmdline.c_str());

  //assert success
  ASSERT_EQ(0, wResult);

  //assert badge content
  ASSERT_TRUE(ra::filesystem::fileExists(badgeFilename.c_str()));
  ASSERT_TRUE(isRightTextBadge(badgeFilename, "10 passed"));
  ASSERT_TRUE(isGreenBadge(badgeFilename));
}

TEST_F(TestSystem, testDisableWarning)
{
  std::string badgeFilename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  std::string cmdline = getSystemTestCommandLine(badgeFilename, 1, 0);
  
  //run subtest command
  printf("exec: %s\n", cmdline.c_str());
  int wResult = system(cmdline.c_str());

  //assert success
  ASSERT_EQ(0, wResult);

  //assert badge content
  ASSERT_TRUE(ra::filesystem::fileExists(badgeFilename.c_str()));
  ASSERT_TRUE(isRightTextBadge(badgeFilename, "1 failed"));
  ASSERT_TRUE(isFailedBadge(badgeFilename));
}

TEST_F(TestSystem, testWarning)
{
  std::string badgeFilename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  std::string cmdline = getSystemTestCommandLine(badgeFilename, 6, 90);
  
  //run subtest command
  printf("exec: %s\n", cmdline.c_str());
  int wResult = system(cmdline.c_str());

  //assert success
  ASSERT_EQ(0, wResult);

  //assert badge content
  ASSERT_TRUE(ra::filesystem::fileExists(badgeFilename.c_str()));
  ASSERT_TRUE(isRightTextBadge(badgeFilename, "6 failed"));
  ASSERT_TRUE(isWarningBadge(badgeFilename));
}
