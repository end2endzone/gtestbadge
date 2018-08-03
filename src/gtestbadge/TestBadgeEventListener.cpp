#include "TestBadgeEventListener.h"
#include "BadgeEventListener.h"
#include "rapid.h"

std::vector<std::string> gTestFiles2;
std::string gTestFolder2 = "tests/";

void TestBadgeEventListener::SetUpTestCase()
{
}

void TestBadgeEventListener::TearDownTestCase()
{
  //build an HTML file viewer

  const std::string filename = gTestFolder2 + /*getTestSuiteName()*/ "TestBadgeEventListener" + ".html";
  FILE * f = fopen(filename.c_str(), "w");
  if (!f)
    return;

  //print header
  fputs(""
"<html>\n"
"<head></head>\n"
"<body>\n"
"  <table>\n"
"    <tbody>\n"
"      <td>File</td>\n"
"      <td>Image</td>\n"
"    </tbody>\n"
, f);

  for(size_t i=0; i<gTestFiles2.size(); i++)
  {
    const std::string & testFile = gTestFiles2[i];
    fprintf(f, "    <tr><td>%s</td><td><img src=\"%s\" /></td></tr>\n", testFile.c_str(), testFile.c_str());
  }

  //print footer
  fputs(""
"  </table>\n"
"</body>\n"
"</html>\n"
, f);

  fclose(f);
}

void TestBadgeEventListener::SetUp()
{
}

void TestBadgeEventListener::TearDown()
{
}

TEST_F(TestBadgeEventListener, testPassedNoIcon)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles2.push_back(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder2 + filename).c_str(), 51, 0, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testWarningNoIcon)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles2.push_back(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder2 + filename).c_str(), 51, 4, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testFailNoIcon)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles2.push_back(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder2 + filename).c_str(), 1, 99, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testPassedAppveyorIcon)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles2.push_back(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder2 + filename).c_str(), 51, 0, 0, BadgeEventListener::ICON_APPVEYOR);
  ASSERT_TRUE(saved);
}
