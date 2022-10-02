#include <gtest/gtest.h>
#include <string/check_if_binary_string_has_at_most_one_segment_of_ones.cpp>

TEST(检查二进制字符串字段, checkOnesSegment) {
  // 示例 1：
  // 输入：s = "1001"
  // 输出：false
  // 解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
  Solution solution;
  EXPECT_FALSE(solution.checkOnesSegment("1001"));

  // 示例 2：
  // 输入：s = "110"
  // 输出：true
  EXPECT_TRUE(solution.checkOnesSegment("110"));
}
