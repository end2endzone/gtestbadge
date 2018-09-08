#pragma once

#include <gtest/gtest.h>

class TestSystem : public ::testing::Test
{
public:
  virtual void SetUp();
  virtual void TearDown();
};
