/**********************************************************************************
 * MIT License
 * 
 * Copyright (c) 2018 Antoine Beauchamp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdio.h>

#include "gtestbadge/Badge.h"
#include "gtestbadge/BadgeEventListener.h"
#include "rapidassist/filesystem.h"

bool processBadge(const char * filename, int success, int failures)
{
  std::string sample_dir = SAMPLES_DIRECTORY;
  std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + filename;

  printf("Generating sample badge '%s'\n", filepath.c_str());
  if ( ! BadgeEventListener::generateBadge(filepath.c_str(), success, failures, 0, BadgeEventListener::ICON_NONE, BadgeEventListener::DEFAULT_WARNING_RATIO))
  {
    return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  std::string sample_dir = SAMPLES_DIRECTORY;

  //create 'samples' directory
  if (!ra::filesystem::createFolder(sample_dir.c_str()))
  {
    return __LINE__;
  }

  //passed
  if (!processBadge("sample_passed.svg", 56, 0))
  {
    return __LINE__;
  }

  //warning
  if (!processBadge("sample_warning.svg", 56, 4))
  {
    return __LINE__;
  }

  //error
  if (!processBadge("sample_error.svg", 56, 17))
  {
    return __LINE__;
  }

  //warning disabled
  if (!processBadge("sample_warning_disabled.svg", 1, 1))
  {
    return __LINE__;
  }

  //icon appveyor
  {
    std::string sample_dir = SAMPLES_DIRECTORY;
    std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + "sample_icon_appveyor.svg";

    printf("Generating sample badge '%s'\n", filepath.c_str());
    if ( ! BadgeEventListener::generateBadge(filepath.c_str(), 42, 0, 0, BadgeEventListener::ICON_APPVEYOR, BadgeEventListener::DEFAULT_WARNING_RATIO))
    {
      return __LINE__;
    }
  }

  //icon travis
  {
    std::string sample_dir = SAMPLES_DIRECTORY;
    std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + "sample_icon_travis.svg";

    printf("Generating sample badge '%s'\n", filepath.c_str());
    if ( ! BadgeEventListener::generateBadge(filepath.c_str(), 42, 0, 0, BadgeEventListener::ICON_TRAVIS, BadgeEventListener::DEFAULT_WARNING_RATIO))
    {
      return __LINE__;
    }
  }

  //custom
  {
    Badge b;
    b.setLeftText("Progress");
    b.setRightBackgroundColor("#00a2e8");
    b.setRightText("92%");
    std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + "sample_custom_progress.svg";
    printf("Generating sample badge '%s'\n", filepath.c_str());
    bool saved = b.save(filepath.c_str());
    if (!saved)
    {
      return __LINE__;
    }
  }

  //custom facebook icon
  {
    const char * FACEBOOK_ICON = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4KPCFET0NUWVBFIHN2ZyBQVUJMSUMgIi0vL1czQy8vRFREIFNWRyAxLjAvL0VOIiAiaHR0cDovL3d3dy53My5vcmcvVFIvMjAwMS9SRUMtU1ZHLTIwMDEwOTA0L0RURC9zdmcxMC5kdGQiPgo8c3ZnIHZlcnNpb249IjEuMCIgZmlsbD0iI2ZmZiIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiB4PSIwcHgiIHk9IjBweCIgd2lkdGg9IjE2cHgiIGhlaWdodD0iMTZweCIgdmlld0JveD0iMCAwIDI1MCA1MTAiPgo8cGF0aCBkPSJNMTgwIDUxMkg5OC4wMDhjLTEzLjY5NSAwLTI0LjgzNi0xMS4xNC0yNC44MzYtMjQuODM2VjMwMi4yMjdIMjUuMzM2QzExLjY0IDMwMi4yMjcuNSAyOTEuMDgyLjUgMjc3LjM5di03OS4yNDZjMC0xMy42OTYgMTEuMTQtMjQuODM2IDI0LjgzNi0yNC44MzZoNDcuODM2di0zOS42ODRjMC0zOS4zNDggMTIuMzU1LTcyLjgyNCAzNS43MjYtOTYuODA1QzEzMi4zNzUgMTIuNzMgMTY1LjE4NCAwIDIwMy43NzggMGw2Mi41My4xMDJjMTMuNjcyLjAyMyAyNC43OTQgMTEuMTY0IDI0Ljc5NCAyNC44MzV2NzMuNTc5YzAgMTMuNjk1LTExLjEzNyAyNC44MzYtMjQuODI5IDI0LjgzNmwtNDIuMTAxLjAxNWMtMTIuODQgMC0xNi4xMSAyLjU3NC0xNi44MDkgMy4zNjMtMS4xNTIgMS4zMS0yLjUyMyA1LjAwOC0yLjUyMyAxNS4yMjN2MzEuMzUyaDU4LjI3YzQuMzg2IDAgOC42MzYgMS4wODIgMTIuMjg4IDMuMTIgNy44OCA0LjQwMyAxMi43NzggMTIuNzI3IDEyLjc3OCAyMS43MjNsLS4wMzEgNzkuMjQ3YzAgMTMuNjg3LTExLjE0MSAyNC44MjgtMjQuODM2IDI0LjgyOGgtNTguNDd2MTg0Ljk0MUMyMDQuODQgNTAwLjg2IDE5My42OTYgNTEyIDE4MCA1MTJ6Ii8+Cjwvc3ZnPg==";
    Badge b;
    b.setBase64Icon(FACEBOOK_ICON);
    b.setLeftText("Friends");
    b.setLeftBackgroundColor("#3b5998");
    b.setLeftForegroundColor("#fff");
    b.setRightBackgroundColor("#fff");
    b.setRightForegroundColor("#000");
    b.setRightText("357");
    std::string filepath = sample_dir + ra::filesystem::getPathSeparatorStr() + "sample_custom_facebook.svg";
    printf("Generating sample badge '%s'\n", filepath.c_str());
    bool saved = b.save(filepath.c_str());
    if (!saved)
    {
      return __LINE__;
    }
  }

  return 0;
}
