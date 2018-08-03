#pragma once

#include <gtest/gtest.h>

class TestBar : public ::testing::Test
{
public:
  virtual void SetUp();
  virtual void TearDown();
};
