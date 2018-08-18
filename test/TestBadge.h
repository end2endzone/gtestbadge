#pragma once

#include <gtest/gtest.h>

class TestBadge : public ::testing::Test
{
public:
  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();
};
