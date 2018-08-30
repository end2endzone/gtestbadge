#include "TestBadge.h"
#include "gtestbadge/Badge.h"
#include "rapidassist/strings.h"
#include "rapidassist/gtesthelp.h"
#include "ImageListBuilder.h"

using ra::strings::toString;

ImageListBuilder gTestBadgeBuilder;
std::string gTestFolder = "tests/";

const char * ICON_CC_SAMPLING   = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48IURPQ1RZUEUgc3ZnIFBVQkxJQyAiLS8vVzNDLy9EVEQgU1ZHIDEuMC8vRU4iICJodHRwOi8vd3d3LnczLm9yZy9UUi8yMDAxL1JFQy1TVkctMjAwMTA5MDQvRFREL3N2ZzEwLmR0ZCI+PHN2ZyB2ZXJzaW9uPSIxLjAiIGlkPSJMYXllcl8xIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIiB4PSIwcHgiIHk9IjBweCIgd2lkdGg9IjY0cHgiIGhlaWdodD0iNjRweCIgdmlld0JveD0iNS41IC0zLjUgNjQgNjQiIGVuYWJsZS1iYWNrZ3JvdW5kPSJuZXcgNS41IC0zLjUgNjQgNjQiIHhtbDpzcGFjZT0icHJlc2VydmUiPjxnPjxjaXJjbGUgZmlsbD0iI0ZGRkZGRiIgY3g9IjM4LjA1IiBjeT0iMjguNDY4IiByPSIyOS40ODIiLz48Zz48cGF0aCBkPSJNMzcuNDQzLTMuNWM4Ljk4OCwwLDE2LjU4LDMuMDk2LDIyLjc3LDkuMjg2QzY2LjQwNCwxMS45NzYsNjkuNSwxOS41NDcsNjkuNSwyOC41YzAsOC45NTQtMy4wNDksMTYuNDM3LTkuMTQ1LDIyLjQ1NiBDNTMuOTE4LDU3LjMxOSw0Ni4yNzksNjAuNSwzNy40NDMsNjAuNWMtOC42ODcsMC0xNi4xODItMy4xNDQtMjIuNDg2LTkuNDNDOC42NTEsNDQuNzg0LDUuNSwzNy4yNjIsNS41LDI4LjUgYzAtOC43NjEsMy4xNDQtMTYuMzQyLDkuNDI5LTIyLjc0MkMyMS4xMDEtMC40MTUsMjguNjA0LTMuNSwzNy40NDMtMy41eiBNMzcuNTI5LDIuMjcyYy03LjI1NywwLTEzLjQwMSwyLjU1My0xOC40MjgsNy42NTcgYy01LjIyLDUuMjk2LTcuODI5LDExLjQ4Ni03LjgyOSwxOC41NzJzMi41OSwxMy4yMiw3Ljc3MSwxOC4zOThjNS4xODEsNS4xODIsMTEuMzUyLDcuNzcxLDE4LjUxNCw3Ljc3MSBjNy4xNjIsMCwxMy4zNzEtMi42MDcsMTguNjI5LTcuODI4YzUuMDI5LTQuODc3LDcuNTQzLTEwLjk5MSw3LjU0My0xOC4zNDNjMC03LjMxNC0yLjU1My0xMy41MDQtNy42NTYtMTguNTcxIEM1MC45NjcsNC44MjQsNDQuNzg1LDIuMjcyLDM3LjUyOSwyLjI3MnogTTM4LjAxNCw5LjEyOGMwLjM4MS0wLjAzOCwwLjcxNSwwLjA2NywxLjAwMiwwLjMxNCBjMC4yODUsMC4yNDksMC40NDUsMC41NjMsMC40ODQsMC45NDN2MC4yMjlsMC44NTcsMTMuODI4bDAuNjI5LTcuNjU3YzAtMC4zODEsMC4xMzMtMC43MDUsMC4zOTgtMC45NzFzMC41OTItMC40MDEsMC45NzEtMC40MDEgYzAuMzgxLDAsMC43MDUsMC4xMzQsMC45NzMsMC40MDFjMC4yNjYsMC4yNjcsMC40LDAuNTksMC40LDAuOTcxdjAuMjI4bDAuNzQsMTAuMjg2bDAuNzQ0LTguMjg1IGMwLjAzNy0wLjM0MiwwLjE4Mi0wLjYyOSwwLjQzLTAuODU3YzAuMjQ2LTAuMjI5LDAuNTQxLTAuMzQyLDAuODg1LTAuMzQyczAuNjQ4LDAuMTA2LDAuOTE0LDAuMzE0IGMwLjI2OCwwLjIxLDAuNDIsMC40ODYsMC40NTksMC44MjlsMS40ODYsMTIuNDU3bDAuNjg2LTEuNjU3YzAuMjI5LTAuNTcyLDAuNjY2LTAuODU4LDEuMzEyLTAuODU4aDcuNDg2djIuNzQ0aC02LjU3MiBsLTIuMzQyLDUuNzE0Yy0wLjI2OCwwLjY4NS0wLjc2NCwwLjk3Mi0xLjQ4NiwwLjg1NmMtMC4zNDItMC4wMzgtMC42MTktMC4xNzItMC44MjgtMC40cy0wLjMzNC0wLjUxNC0wLjM3MS0wLjg1N2wtMC41MTQtNC4xMTQgbC0wLjk3MSwxMS45NDJjLTAuMDM5LDAuMzQxLTAuMTgyLDAuNjI4LTAuNDMsMC44NTZzLTAuNTQzLDAuMzQzLTAuODg3LDAuMzQzYy0wLjM0MiwwLTAuNjQ2LTAuMTE0LTAuOTE0LTAuMzQzIGMtMC4yNjYtMC4yMjktMC40MTgtMC41MTMtMC40NTctMC44NTZ2LTAuMTcybC0wLjc5OS05Ljg4NmwtMC42ODYsOS4zMTVjLTAuMDc4LDAuMzQyLTAuMjQsMC42MjktMC40ODYsMC44NTcgYy0wLjI0OCwwLjIyOS0wLjU0MywwLjM0Mi0wLjg4NywwLjM0MmMtMC4zNDIsMC0wLjY0OC0wLjExMy0wLjkxNC0wLjM0MnMtMC40Mi0wLjUxNS0wLjQ1Ny0wLjg1N1Y0My44N2wtMC43NDQtMTEuMTQzIGwtMC43NDIsMTIuMjI5djAuMTcyYzAsMC4zODItMC4xMzUsMC43MTMtMC40LDAuOTk5cy0wLjU5LDAuNDMtMC45NzEsMC40M2MtMC4zODMsMC0wLjcwNS0wLjE0NC0wLjk3MS0wLjQzIGMtMC4yNjgtMC4yODYtMC40MDItMC42MTctMC40MDItMC45OTl2LTAuMTE1bC0wLjc0Mi0xMS4zMTNsLTAuNjg2LDEwLjkxNHYwLjE3MWMtMC4wNzcsMC4zNDQtMC4yMzgsMC42My0wLjQ4NSwwLjg1NyBjLTAuMjQ4LDAuMjI5LTAuNTQzLDAuMzQzLTAuODg1LDAuMzQzcy0wLjY0OC0wLjExNC0wLjkxNC0wLjM0M2MtMC4yNjctMC4yMjgtMC40MTktMC41MTQtMC40NTgtMC44NTd2LTAuMTcxaC0wLjA1NnYtMC4xNyBsLTAuOC0xMS40MjhsLTAuNjI5LDcuMzEzYy0wLjAzOCwwLjM0NC0wLjE5MSwwLjYzLTAuNDU3LDAuODU3Yy0wLjI2NywwLjIyOS0wLjU3MSwwLjM0NC0wLjkxNCwwLjM0NCBjLTAuMzQzLDAtMC42MzktMC4xMDUtMC44ODctMC4zMTVjLTAuMjQ4LTAuMjA4LTAuNDEtMC40ODUtMC40ODYtMC44MjhsLTEuNDI5LTkuODI4bC0wLjE3MSwwLjM0MSBjLTAuMjI4LDAuNDk2LTAuNjQ4LDAuNzQ0LTEuMjU4LDAuNzQ0aC02LjYyOFYyOC45aDUuNzcybDEuNzcxLTMuNmMwLjI2Ny0wLjYwOSwwLjczMi0wLjg2NywxLjQtMC43NzIgYzAuNjY2LDAuMDk1LDEuMDU3LDAuNDY3LDEuMTcxLDEuMTE0bDAuNCwyLjYyOGwxLjA4NS0xMi42MjhjMC0wLjM4MSwwLjEzMy0wLjcwNSwwLjQtMC45NzFzMC41OS0wLjQwMSwwLjk3MS0wLjQwMSBzMC43MDQsMC4xMzQsMC45NzEsMC40MDFjMC4yNjcsMC4yNjcsMC4zOTksMC41OSwwLjM5OSwwLjk3MXYwLjIyOGwwLjYyOSw4LjkxNWwwLjg1Ny0xMS45NDJ2LTAuMTcxIGMwLjAzNy0wLjM0MywwLjE4LTAuNjI5LDAuNDI4LTAuODU3YzAuMjQ3LTAuMjI4LDAuNTQyLTAuMzQyLDAuODg2LTAuMzQyczAuNjQ4LDAuMTE0LDAuOTE0LDAuMzQyIGMwLjI2OCwwLjIyOSwwLjQxOCwwLjUxNCwwLjQ1NywwLjg1N3YwLjE3MWwwLjY4NiwxMC40bDAuODAxLTEyLjYyOHYtMC4yMjljMC0wLjM0MiwwLjEyMy0wLjYyOSwwLjM3MS0wLjg1NyBDMzcuMzc1LDkuMywzNy42Nyw5LjE2NywzOC4wMTQsOS4xMjh6Ii8+PC9nPjwvZz48L3N2Zz4=";
const char * ICON_CC_SA         = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48IURPQ1RZUEUgc3ZnIFBVQkxJQyAiLS8vVzNDLy9EVEQgU1ZHIDEuMC8vRU4iICJodHRwOi8vd3d3LnczLm9yZy9UUi8yMDAxL1JFQy1TVkctMjAwMTA5MDQvRFREL3N2ZzEwLmR0ZCI+PHN2ZyB2ZXJzaW9uPSIxLjAiIGlkPSJMYXllcl8xIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIiB4PSIwcHgiIHk9IjBweCIgd2lkdGg9IjY0cHgiIGhlaWdodD0iNjRweCIgdmlld0JveD0iNS41IC0zLjUgNjQgNjQiIGVuYWJsZS1iYWNrZ3JvdW5kPSJuZXcgNS41IC0zLjUgNjQgNjQiIHhtbDpzcGFjZT0icHJlc2VydmUiPjxnPjxjaXJjbGUgZmlsbD0iI0ZGRkZGRiIgY3g9IjM2Ljk0NCIgY3k9IjI4LjYzMSIgcj0iMjkuMTA1Ii8+PGc+PHBhdGggZD0iTTM3LjQ0My0zLjVjOC45NTEsMCwxNi41MzEsMy4xMDUsMjIuNzQyLDkuMzE1QzY2LjM5MywxMS45ODcsNjkuNSwxOS41NDgsNjkuNSwyOC41YzAsOC45NTQtMy4wNDksMTYuNDU3LTkuMTQ1LDIyLjUxNCBDNTMuOTE4LDU3LjMzOCw0Ni4yNzksNjAuNSwzNy40NDMsNjAuNWMtOC42NDksMC0xNi4xNTMtMy4xNDMtMjIuNTE0LTkuNDI5QzguNjQ0LDQ0Ljc4Niw1LjUsMzcuMjY0LDUuNSwyOC41MDEgYzAtOC43MjMsMy4xNDQtMTYuMjg1LDkuNDI5LTIyLjY4NUMyMS4xMzgtMC4zOTUsMjguNjQzLTMuNSwzNy40NDMtMy41eiBNMzcuNTU3LDIuMjcyYy03LjI3NiwwLTEzLjQyOCwyLjU3Mi0xOC40NTcsNy43MTUgYy01LjIyLDUuMjk2LTcuODI5LDExLjQ2Ny03LjgyOSwxOC41MTNjMCw3LjEyNSwyLjU5LDEzLjI1Nyw3Ljc3LDE4LjRjNS4xODEsNS4xODIsMTEuMzUyLDcuNzcxLDE4LjUxNCw3Ljc3MSBjNy4xMjMsMCwxMy4zMzQtMi42MDksMTguNjI5LTcuODI4YzUuMDI5LTQuODc2LDcuNTQzLTEwLjk5LDcuNTQzLTE4LjM0M2MwLTcuMzEzLTIuNTUzLTEzLjQ4NS03LjY1Ni0xOC41MTMgQzUxLjAwNCw0Ljg0Miw0NC44MzIsMi4yNzIsMzcuNTU3LDIuMjcyeiBNMjMuMjcxLDIzLjk4NWMwLjYwOS0zLjkyNCwyLjE4OS02Ljk2Miw0Ljc0Mi05LjExNCBjMi41NTItMi4xNTIsNS42NTYtMy4yMjgsOS4zMTQtMy4yMjhjNS4wMjcsMCw5LjAyOSwxLjYyLDEyLDQuODU2YzIuOTcxLDMuMjM4LDQuNDU3LDcuMzkxLDQuNDU3LDEyLjQ1NyBjMCw0LjkxNS0xLjU0Myw5LTQuNjI3LDEyLjI1NmMtMy4wODgsMy4yNTYtNy4wODYsNC44ODYtMTIuMDAyLDQuODg2Yy0zLjYxOSwwLTYuNzQzLTEuMDg1LTkuMzcxLTMuMjU3IGMtMi42MjktMi4xNzItNC4yMDktNS4yNTctNC43NDMtOS4yNTdIMzEuMWMwLjE5LDMuODg2LDIuNTMzLDUuODI5LDcuMDI5LDUuODI5YzIuMjQ2LDAsNC4wNTctMC45NzIsNS40MjgtMi45MTQgYzEuMzczLTEuOTQyLDIuMDU5LTQuNTM0LDIuMDU5LTcuNzcxYzAtMy4zOTEtMC42MjktNS45NzEtMS44ODUtNy43NDNjLTEuMjU4LTEuNzcxLTMuMDY2LTIuNjU3LTUuNDMtMi42NTcgYy00LjI2OCwwLTYuNjY3LDEuODg1LTcuMiw1LjY1NmgyLjM0M2wtNi4zNDIsNi4zNDNsLTYuMzQzLTYuMzQzTDIzLjI3MSwyMy45ODVMMjMuMjcxLDIzLjk4NXoiLz48L2c+PC9nPjwvc3ZnPg==";
const char * ICON_CC_SHARE      = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48IURPQ1RZUEUgc3ZnIFBVQkxJQyAiLS8vVzNDLy9EVEQgU1ZHIDEuMC8vRU4iICJodHRwOi8vd3d3LnczLm9yZy9UUi8yMDAxL1JFQy1TVkctMjAwMTA5MDQvRFREL3N2ZzEwLmR0ZCI+PHN2ZyB2ZXJzaW9uPSIxLjAiIGlkPSJMYXllcl8xIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIiB4PSIwcHgiIHk9IjBweCIgd2lkdGg9IjY0cHgiIGhlaWdodD0iNjRweCIgdmlld0JveD0iNS41IC0zLjUgNjQgNjQiIGVuYWJsZS1iYWNrZ3JvdW5kPSJuZXcgNS41IC0zLjUgNjQgNjQiIHhtbDpzcGFjZT0icHJlc2VydmUiPjxnPjxjaXJjbGUgZmlsbD0iI0ZGRkZGRiIgY3g9IjM3Ljk0NiIgY3k9IjI4Ljg4NyIgcj0iMjkuNzA0Ii8+PGc+PHBhdGggZD0iTTM3LjQ0My0zLjVjOC45NTEsMCwxNi41MzEsMy4xMDUsMjIuNzQyLDkuMzE1QzY2LjM5MywxMS45ODcsNjkuNSwxOS41NDgsNjkuNSwyOC41YzAsOC45NTQtMy4wNDksMTYuNDU3LTkuMTQ1LDIyLjUxNCBDNTMuOTE4LDU3LjMzOCw0Ni4yNzksNjAuNSwzNy40NDMsNjAuNWMtOC42NDksMC0xNi4xNTMtMy4xNDMtMjIuNTE0LTkuNDI5QzguNjQ0LDQ0Ljc4Niw1LjUsMzcuMjY0LDUuNSwyOC41MDEgYzAtOC43MjMsMy4xNDQtMTYuMjg1LDkuNDI5LTIyLjY4NUMyMS4xMzgtMC4zOTUsMjguNjQzLTMuNSwzNy40NDMtMy41eiBNMzcuNTU3LDIuMjcyYy03LjI3NiwwLTEzLjQyOCwyLjU3Mi0xOC40NTcsNy43MTUgYy01LjIyLDUuMjk2LTcuODI5LDExLjQ2Ny03LjgyOSwxOC41MTNjMCw3LjEyNSwyLjU5LDEzLjI1Nyw3Ljc3LDE4LjRjNS4xODEsNS4xODIsMTEuMzUyLDcuNzcxLDE4LjUxNCw3Ljc3MSBjNy4xMjMsMCwxMy4zMzQtMi42MDksMTguNjI5LTcuODI4YzUuMDI5LTQuODc2LDcuNTQzLTEwLjk5LDcuNTQzLTE4LjM0M2MwLTcuMzEzLTIuNTUzLTEzLjQ4NS03LjY1Ni0xOC41MTMgQzUxLjAwNCw0Ljg0Miw0NC44MzIsMi4yNzIsMzcuNTU3LDIuMjcyeiBNNTAuNTg2LDE5LjM1N2MwLjQ5NCwwLDAuOTE0LDAuMTcxLDEuMjU2LDAuNTEzYzAuMzQ0LDAuMzQzLDAuNTE2LDAuNzYzLDAuNTE2LDEuMjU4IHYyMy41NDJjMCwwLjQ5NS0wLjE3MiwwLjkxNC0wLjUxNiwxLjI1NmMtMC4zNDIsMC4zNDMtMC43NjIsMC41MTYtMS4yNTYsMC41MTZIMzMuMTU3Yy0wLjQ5NiwwLTAuOTE0LTAuMTcxLTEuMjU4LTAuNTE2IGMtMC4zNDQtMC4zNDMtMC41MTQtMC43NjEtMC41MTQtMS4yNTZ2LTYuOTczaC02Ljk3MWMtMC40OTcsMC0wLjkxNS0wLjE3LTEuMjU4LTAuNTEzYy0wLjM0Mi0wLjM0Mi0wLjUxNC0wLjc2MS0wLjUxNC0xLjI1OCBWMTIuMzg2YzAtMC40NTgsMC4xNTEtMC44NDgsMC40NTgtMS4xNzFjMC4zMDMtMC4zMjMsMC42ODUtMC41MjMsMS4xNDItMC42aDAuMTcxaDE3LjQyOGMwLjQ5NCwwLDAuOTE0LDAuMTcxLDEuMjU4LDAuNTE0IGMwLjM0MiwwLjM0MiwwLjUxNCwwLjc2MywwLjUxNCwxLjI1OHY2Ljk3Mkg1MC41ODZ6IE0yNi4xMjgsMzQuMjE0aDUuMjU3VjIxLjEyOGMwLTAuNDU3LDAuMTUxLTAuODQ3LDAuNDU4LTEuMTcxIGMwLjMwNC0wLjMyMiwwLjY2Ny0wLjUyMywxLjA4NS0wLjZoMC4yMjhoNi45NzJ2LTUuMmgtMTRWMzQuMjE0eiBNNDguODcxLDIyLjg0MmgtMTR2MjAuMDU4aDE0VjIyLjg0MnoiLz48L2c+PC9nPjwvc3ZnPg==";

void TestBadge::SetUpTestCase()
{
}

void TestBadge::TearDownTestCase()
{
  //build an HTML file viewer
  const std::string filename = gTestFolder + /*getTestSuiteName()*/ "TestBadge" + ".html";
  ASSERT_TRUE( gTestBadgeBuilder.save(filename) );
}

void TestBadge::SetUp()
{
}

void TestBadge::TearDown()
{
}

TEST_F(TestBadge, testDefault)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testFull)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setHeight(60);
  b.setLeftBackgroundColor("#ffc90e"); //gold
  b.setLeftForegroundColor("#000");
  b.setRightBackgroundColor("#f00"); //red
  b.setRightForegroundColor("#00f"); //blue
  b.setLeftFontSize(8);
  b.setRightFontSize(30);
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
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftTextLeftPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftTextRightPadding)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftTextRightPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightTextLeftPadding)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightTextLeftPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightTextRightPadding)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightTextRightPadding(50);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftText)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftText("foo");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightText)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightText("bar");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftWidth)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftWidth(300);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightWidth)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightWidth(300);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftBackColor)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftBackgroundColor("#0f0");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightBackColor)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#00f");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftFrontColor)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftForegroundColor("#0f0");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightFrontColor)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightForegroundColor("#00f");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testTestPassed)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#4c1"); //brightgreen
  b.setLeftText("tests");
  b.setRightText("51 passed");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testTestWarning)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#fe7d37");  //orange
  b.setLeftText("tests");
  b.setRightText("2 failed");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testTestFailed)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#e05d44");  //red
  b.setLeftText("tests");
  b.setRightText("99 failed");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testBuildPassed)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#4c1"); //brightgreen
  b.setLeftText("build");
  b.setRightText("success");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testBuildFailed)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#e05d44");  //red
  b.setLeftText("build");
  b.setRightText("failed");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLicenseBadge)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#ffc90e"); //gold
  b.setLeftText("License");
  b.setRightText("MIT");
  b.setRightTextLeftPadding(3);
  b.setRightTextRightPadding(3);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testUnknown)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftText("Unknown");
  b.setRightText("!!!!!");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testCoverage)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setRightBackgroundColor("#e05d44");  //red
  b.setLeftText("Coverage");
  b.setRightText("3%");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testRightTextEmpty)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftText("right empty");
  b.setRightText("");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testLeftTextEmpty)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setLeftText("");
  b.setRightText("left empty");
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testIcon)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setBase64Icon(ICON_CC_SAMPLING);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testIconBig)
{
  const std::string filename = ra::gtesthelp::getTestQualifiedName() + ".svg";
  gTestBadgeBuilder.addImage(filename);

  Badge b;
  b.setBase64Icon(ICON_CC_SHARE);
  b.setHeight(60);
  bool saved = b.save(gTestFolder + filename);
  ASSERT_TRUE(saved);
}

TEST_F(TestBadge, testFontSize)
{
  for(int font_size = 1; font_size <= 30; font_size++)
  {
    const std::string filename = ra::gtesthelp::getTestQualifiedName() + "." + toString(font_size) + ".svg";
    gTestBadgeBuilder.addImage(filename);

    Badge b;
    b.setHeight(Badge::HEIGHT_AUTO);
    b.setLeftText("FontSize");
    b.setRightText(toString(font_size));
    b.setRightFontSize(font_size);
    bool saved = b.save(gTestFolder + filename);
    ASSERT_TRUE(saved);
  }
}

TEST_F(TestBadge, testHeight)
{
  for(int height = 10; height <= 100; height+=10)
  {
    const std::string filename = ra::gtesthelp::getTestQualifiedName() + "." + toString(height) + ".svg";
    gTestBadgeBuilder.addImage(filename);

    Badge b;
    b.setHeight(height);
    b.setLeftText("Height");
    b.setRightText(toString(height));
    bool saved = b.save(gTestFolder + filename);
    ASSERT_TRUE(saved);
  }
}

TEST_F(TestBadge, testIconSizes)
{
  for(int height = 10; height <= 100; height+=10)
  {
    const std::string filename = ra::gtesthelp::getTestQualifiedName() + "." + toString(height) + ".svg";
    gTestBadgeBuilder.addImage(filename);

    Badge b;
    b.setHeight(height);
    b.setBase64Icon(ICON_CC_SA);
    b.setLeftText("Height");
    b.setRightText(toString(height));
    bool saved = b.save(gTestFolder + filename);
    ASSERT_TRUE(saved);
  }
}

TEST_F(TestBadge, testMultipleSave)
{
  Badge b;
  b.setBase64Icon(ICON_CC_SHARE);
  b.setHeight(60);

  for(int i = 0; i < 5; i++)
  {
    const std::string filename = ra::gtesthelp::getTestQualifiedName() + "." + toString(i) + ".svg";
    gTestBadgeBuilder.addImage(filename);

    bool saved = b.save(gTestFolder + filename);
    ASSERT_TRUE(saved);
  }
}
