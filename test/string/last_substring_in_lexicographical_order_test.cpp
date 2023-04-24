#include <string/last_substring_in_lexicographical_order.cpp>

TEST(按字典序排在最后的子串, lastSubstring) {
  // 示例 1：
  // 输入：s = "abab"
  // 输出："bab"
  // 解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba",
  // "bab"]。按字典序排在最后的子串是 "bab"。
  Solution solution;
  string s = "abab";
  EXPECT_EQ(solution.lastSubstring(s), "bab");

  // 示例 2：
  // 输入：s = "leetcode"
  // 输出："tcode"
  s = "leetcode";
  EXPECT_EQ(solution.lastSubstring(s), "tcode");
}
