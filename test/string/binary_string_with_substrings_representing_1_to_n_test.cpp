#include <string/binary_string_with_substrings_representing_1_to_n.cpp>

TEST(子串能表示从1到N数字的二进制串, queryString) {
  // 示例 1：
  // 输入：s = "0110", n = 3
  // 输出：true
  Solution solution;
  string s = "0110";
  int n = 3;
  EXPECT_TRUE(solution.queryString(s, n));

  // 示例 2：
  // 输入：s = "0110", n = 4
  // 输出：false
  s = "0110";
  n = 4;
  EXPECT_FALSE(solution.queryString(s, n));
}
