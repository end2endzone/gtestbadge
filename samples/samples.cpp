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

int main(int argc, char **argv)
{
  //create 'samples' directory
  if (!ra::filesystem::createFolder("samples"))
  {
    return __LINE__;
  }

  //passed
  if ( ! BadgeEventListener::generateBadge("samples/sample_passed.svg", 56, 0, 0, BadgeEventListener::ICON_NONE, BadgeEventListener::DEFAULT_WARNING_RATIO))
  {
    return __LINE__;
  }

  //warning
  if ( ! BadgeEventListener::generateBadge("samples/sample_warning.svg", 56, 4, 0, BadgeEventListener::ICON_NONE, BadgeEventListener::DEFAULT_WARNING_RATIO))
  {
    return __LINE__;
  }

  //error
  if ( ! BadgeEventListener::generateBadge("samples/sample_error.svg", 56, 17, 0, BadgeEventListener::ICON_NONE, BadgeEventListener::DEFAULT_WARNING_RATIO))
  {
    return __LINE__;
  }

  //custom
  {
    Badge b;
    b.setLeftText("Progress");
    b.setRightBackgroundColor("#00a2e8");
    b.setRightText("92%");
    bool saved = b.save("samples/sample_custom_progress.svg");
    if (!saved)
    {
      return __LINE__;
    }
  }

  return 0;
}
