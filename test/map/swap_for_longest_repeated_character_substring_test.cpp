#include <map/swap_for_longest_repeated_character_substring.cpp>

TEST(单字符重复子串的最大长度, maxRepOpt1) {
  Solution solution;
  // 示例 1：
  // 输入：text = "ababa"
  // 输出：3
  string text = "ababa";
  EXPECT_EQ(solution.maxRepOpt1(text), 3);

  // 示例 2：
  // 输入：text = "aaabaaa"
  // 输出：6
  text = "aaabaaa";
  EXPECT_EQ(solution.maxRepOpt1(text), 6);

  // 示例 3：
  // 输入：text = "aaabbaaa"
  // 输出：4
  text = "aaabbaaa";
  EXPECT_EQ(solution.maxRepOpt1(text), 4);

  // 示例 4：
  // 输入：text = "aaaaa"
  // 输出：5
  text = "aaaaa";
  EXPECT_EQ(solution.maxRepOpt1(text), 5);

  // 示例 5：
  // 输入：text = "abcdef"
  // 输出：1
  text = "abcdef";
  EXPECT_EQ(solution.maxRepOpt1(text), 1);
}
