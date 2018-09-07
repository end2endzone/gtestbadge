# GTestBadge #
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Github Releases](https://img.shields.io/github/release/end2endzone/gtestbadge.svg)](https://github.com/end2endzone/gtestbadge/releases)

GTestBadge is a GoogleTest TestEventListener implementation in c++ for generating a badge based on test results. 

This project also provides a standalone classes for generating generic badges.


## Status ##

Build:

| Service | Build | Tests |
|----|-------|-------|
| AppVeyor | [![Build status](https://img.shields.io/appveyor/ci/end2endzone/GTestBadge/master.svg?logo=appveyor)](https://ci.appveyor.com/project/end2endzone/gtestbadge) | [![Tests status](https://img.shields.io/appveyor/tests/end2endzone/gtestbadge/master.svg?logo=appveyor)](https://ci.appveyor.com/project/end2endzone/gtestbadge/branch/master/tests) |
| Travis CI | [![Build Status](https://img.shields.io/travis/end2endzone/GTestBadge/master.svg?logo=travis&style=flat)](https://travis-ci.org/end2endzone/GTestBadge) |  |

Statistics:

| AppVeyor | Travis CI |
|----------|-----------|
| [![Statistics](https://buildstats.info/appveyor/chart/end2endzone/gtestbadge)](https://ci.appveyor.com/project/end2endzone/gtestbadge/branch/master) | [![Statistics](https://buildstats.info/travisci/chart/end2endzone/gtestbadge)](https://travis-ci.org/end2endzone/gtestbadge) |




# Philosophy #

There is already multiple badge generator systems available online. Most Continuous Integration server used for open source offers some kind of badge support.

AppVeyor and Travis CI already provides 'build status' badges and [shields.io](https://shields.io/#/) also provides badge support based on public metadata of many web sites.

Unfortunately, Travis CI does not provide a test badge and shields.io services can not help because Travis does not support archiving build artifacts.

If you want to provides a test badge in your `README.md` from a test execution on travis, you must do one of the following:

1) Push your test results file from Travis back to Github and have an external service pick up and process the file to generate a badge. As of this writing, shiedls.io do not support parsing junit test results.
2) Process your test results file inside Travis and push a badge to an online image hosting service. However, finding an image hosting portal that can be accessed from the command line is not an easy task.
3) **Process your test results file inside Travis and push a badge back to Github.**

This library helps you implement the 3rd option. It listens for success and failures during googletest execution and, at the end of test case execution, produces a test badge based on test results .




# Usage #

The following instructions show how to use the library.



## Register a BadgeEventListener ##

From your main executable file of a test suite (the one with `main()`).

Add the required include:

```
#include "gtestbadge/BadgeEventListener.h"
```

Register a BadgeEventListener instance before the `RUN_ALL_TESTS()` call:

```cpp
// Adds a BadgeEventListener instance to the end of the test event listener list, 
// **after** the default text output printer and the default XML report generator.
// Note: the insert order is important.
::testing::TestEventListeners & listeners = ::testing::UnitTest::GetInstance()->listeners();
listeners.Append(new BadgeEventListener("mybadge.svg")); //Google Test assumes the ownership of the listener (i.e. it will delete the listener when the test program finishes).
```

By default, BadgeEventListener creates one of the following type of badge:
* `passed` (green background, all tests are successful)
* `warning` (orange background, some tests are failing)
* `failed` (red background, too many tests are failing)



## Configure a BadgeEventListener ##

The BadgeEventListener instance can also be configured to do one of the following:
* Disable console output on error/warnings.
* Query the badge creation result.
* Change the ratio of accepted failures for a displaying a `warning` or `failed` badge.

```cpp
// Adds a BadgeEventListener instance to the end of the test event listener list, 
// **after** the default text output printer and the default XML report generator.
// Note: the insert order is important.
::testing::TestEventListeners & listeners = ::testing::UnitTest::GetInstance()->listeners();

// Create and register a new BadgeEventListener
BadgeEventListener * bel = new BadgeEventListener();
bel->setOutputFilename("mybadge.svg"); //set badge filename
bel->setSilent(true); //disable all console output
bel->setWarningRatio(0.3); //if less than 30% of test fails, show the `warning` badge type. Else, show the `failed` badge type.
listeners.Append(bel); //Google Test assumes the ownership of the listener (i.e. it will delete the listener when the test program finishes).

// Find and run all tests
int wResult = RUN_ALL_TESTS();

// Test badge creation result
if (!bel->getSuccess())
{
  printf("ERROR: Failed saving badge to file '%s'.\n", bel->getOutputFilename().c_str());
}
```



## Disable 'warning' badge ##

By calling `setWarningRatio(0.0)`, one can change the behavior of the BadgeEventListener and disable the `warning` type of badge.

On tests execution, BadgeEventListener creates one of the two types of badge:

* `passed` (green background, all tests are successful)
* `failed` (red background, at least one test fails)



## Create any other badge (customization) ##

The library also have classes for creating generic/custom badges.

```cpp
Badge b;
b.setLeftText("Progress");
b.setRightBackgroundColor("#00cc00");
b.setRightText("92%");
bool saved = b.save(iFilename.c_str());
```





# Build #

Please refer to file [INSTALL.md](INSTALL.md) for details on how installing/building the application.




# Platform #

GTestBadge has been tested with the following platform:

*   Linux x86/x64
*   Windows x86/x64




# Versioning #

We use [Semantic Versioning 2.0.0](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/end2endzone/GTestBadge/tags).




# Authors #

* **Antoine Beauchamp** - *Initial work* - [end2endzone](https://github.com/end2endzone)

See also the list of [contributors](https://github.com/end2endzone/GTestBadge/blob/master/AUTHORS) who participated in this project.




# License #

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

