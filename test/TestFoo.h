#pragma once

#include <gtest/gtest.h>

class TestFoo : public ::testing::Test
{
public:
  virtual void SetUp();
  virtual void TearDown();
};
