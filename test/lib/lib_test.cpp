// 执行编译时间：2023-06-20 15:16:01
#include <gtest/gtest.h>
#include <lib.hpp>

TEST(默认测试, add) {
  int res = add(2, 3);
  EXPECT_EQ(res, 5);
}
