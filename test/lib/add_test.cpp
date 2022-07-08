#include <gtest/gtest.h>
#include <lib.hpp>

TEST(默认测试, add)
{
  EXPECT_EQ(add(2, 3), 5);
}
