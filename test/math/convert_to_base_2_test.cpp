#include <gtest/gtest.h>
#include <math/convert_to_base_2.cpp>

TEST(负二进制转换, baseNeg2) {
  // 示例 1：
  // 输入：n = 2
  // 输出："110"
  // 解释：(-2)2 + (-2)1 = 2
  Solution solution1;
  EXPECT_EQ(solution1.baseNeg2(2), "110");

  // 示例 2：
  // 输入：n = 3
  // 输出："111"
  // 解释：(-2)2 + (-2)1 + (-2)0 = 3
  Solution solution2;
  EXPECT_EQ(solution2.baseNeg2(3), "111");

  // 示例 3：
  // 输入：n = 4
  // 输出："100"
  // 解释：(-2)2 = 4
  Solution solution3;
  EXPECT_EQ(solution3.baseNeg2(4), "100");

  // n=0
  Solution solution4;
  EXPECT_EQ(solution4.baseNeg2(0), "0");

  // n=1
  Solution solution5;
  EXPECT_EQ(solution5.baseNeg2(1), "1");
}