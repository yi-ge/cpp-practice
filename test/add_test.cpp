#include <gtest/gtest.h>

#include "functions.hpp"

TEST(testCase, test)
{
  EXPECT_EQ(add(2, 3), 5);
}
