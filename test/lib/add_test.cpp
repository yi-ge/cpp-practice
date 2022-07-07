#include <gtest/gtest.h>

#include "functions.hpp"

TEST(默认测试, add)
{
  EXPECT_EQ(add(2, 3), 5);
}
