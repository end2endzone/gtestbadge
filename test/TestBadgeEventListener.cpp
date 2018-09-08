#include "TestBadgeEventListener.h"
#include "gtestbadge/BadgeEventListener.h"
#include "rapidassist/strings.h"
#include "rapidassist/gtesthelp.h"
#include "ImageListBuilder.h"

ImageListBuilder gTestBadgeEventListenerBuilder;
extern std::string gTestFolder;

extern bool isRightTextBadge(const std::string & path, const std::string & text);
extern bool isGreenBadge(const std::string & path);
extern bool isWarningBadge(const std::string & path);
extern bool isFailedBadge(const std::string & path);

void TestBadgeEventListener::SetUpTestCase()
{
}

void TestBadgeEventListener::TearDownTestCase()
{
  //build an HTML file viewer
  const std::string filename = gTestFolder + /*getTestSuiteName()*/ "TestBadgeEventListener" + ".html";
  ASSERT_TRUE( gTestBadgeEventListenerBuilder.save(filename) );
}

void TestBadgeEventListener::SetUp()
{
}

void TestBadgeEventListener::TearDown()
{
}

TEST_F(TestBadgeEventListener, testPassedNoIcon)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeEventListenerBuilder.addImage(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder + filename).c_str(), 51, 0, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testWarningNoIcon)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeEventListenerBuilder.addImage(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder + filename).c_str(), 51, 4, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testFailNoIcon)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeEventListenerBuilder.addImage(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder + filename).c_str(), 1, 99, 0, BadgeEventListener::ICON_NONE);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadgeEventListener, testPassedAppveyorIcon)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeEventListenerBuilder.addImage(filename);

  bool saved = BadgeEventListener::generateBadge((gTestFolder + filename).c_str(), 51, 0, 0, BadgeEventListener::ICON_APPVEYOR);
  ASSERT_TRUE(saved);
}
