#include <stack/check_if_word_is_valid_after_substitutions.cpp>

TEST(检查替换后的词是否有效, isValid) {
  Solution solution;

  // 示例 1：
  // 输入：s = "aabcbc"
  // 输出：true
  // 解释：
  // "" -> "abc" -> "aabcbc"
  // 因此，"aabcbc" 有效。
  std::string s1 = "aabcbc";
  EXPECT_EQ(solution.isValid(s1), true);

  // 示例 2：
  // 输入：s = "abcabcababcc"
  // 输出：true
  // 解释：
  // "" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
  // 因此，"abcabcababcc" 有效。
  std::string s2 = "abcabcababcc";
  EXPECT_EQ(solution.isValid(s2), true);

  // 示例 3：
  // 输入：s = "abccba"
  // 输出：false
  // 解释：执行操作无法得到 "abccba" 。
  std::string s3 = "abccba";
  EXPECT_EQ(solution.isValid(s3), false);

  // 示例 4：
  // 输入：s = "abcacb"
  // 输出：false
  // 解释：执行操作无法得到 "abcacb" 。
  std::string s4 = "abcacb";
  EXPECT_EQ(solution.isValid(s4), false);

  // 示例 5：
  // 输入：s = "abacbc"
  // 输出：false
  // 解释：执行操作无法得到 "abacbc" 。
  std::string s5 = "abacbc";
  EXPECT_EQ(solution.isValid(s5), false);
}
