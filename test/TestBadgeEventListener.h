#pragma once

#include <gtest/gtest.h>

class TestBadgeEventListener : public ::testing::Test
{
public:
  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();
};
