// 执行编译时间：2024-01-11 11:49:55
#include <gtest/gtest.h>
#include <lib.hpp>

TEST(默认测试, add) {
  int res = add(2, 3);
  EXPECT_EQ(res, 5);
}
