#include "TestBadge.h"
#include "Badge.h"
#include "rapid.h"

std::vector<std::string> gTestFiles;
std::string gTestFolder = "tests/";

void TestBadge::SetUpTestCase()
{
  _mkdir("tests");
}

void TestBadge::TearDownTestCase()
{
  //build an HTML file viewer

  const std::string filename = gTestFolder + /*getTestSuiteName()*/ "TestBadge" + ".html";
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

  for(size_t i=0; i<gTestFiles.size(); i++)
  {
    const std::string & testFile = gTestFiles[i];
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

void TestBadge::SetUp()
{
}

void TestBadge::TearDown()
{
}

TEST_F(TestBadge, testDefault)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testFull)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftBackgroundColor("#ffc90e"); //gold
  b.setRightBackgroundColor("#f00");
  b.setLeftFontSize(8);
  b.setRightFontSize(20);
  b.setLeftText("foo");
  b.setRightText("bar");
  b.setLeftTextLeftPadding(50);
  b.setLeftWidth(100);
  b.setLeftTextRightPadding(150);
  b.setRightTextLeftPadding(200);
  b.setRightWidth(250);
  b.setRightTextRightPadding(300);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftTextLeftPadding)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftTextLeftPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftTextRightPadding)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftTextRightPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightTextLeftPadding)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setRightTextLeftPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightTextRightPadding)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setRightTextRightPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftText)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftText("foo");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightText)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setRightText("bar");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftWidth)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftWidth(300);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightWidth)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setRightWidth(300);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftColor)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setLeftBackgroundColor("#0f0");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightColor)
{
  const std::string filename = getTestQualifiedName() + ".svg";
  gTestFiles.push_back(filename);

  Badge b;
  b.setRightBackgroundColor("#00f");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}
