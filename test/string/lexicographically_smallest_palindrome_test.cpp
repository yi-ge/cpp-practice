#include <string/lexicographically_smallest_palindrome.cpp>

TEST(字典序最小回文串, makeSmallestPalindrome) {
  Solution solution;
  // 示例 1：
  // 输入：s = "egcfe"
  // 输出："efcfe"
  // 解释：将 "egcfe" 变成回文字符串的最小操作次数为 1 ，修改 1
  // 次得到的字典序最小回文字符串是 "efcfe"，只需将 'g' 改为 'f' 。
  string s = "egcfe";
  EXPECT_EQ(solution.makeSmallestPalindrome(s), "efcfe");

  // 示例 2：
  // 输入：s = "abcd"
  // 输出："abba"
  // 解释：将 "abcd" 变成回文字符串的最小操作次数为 2 ，修改 2
  // 次得到的字典序最小回文字符串是 "abba" 。
  s = "abcd";
  EXPECT_EQ(solution.makeSmallestPalindrome(s), "abba");

  // 示例 3：
  // 输入：s = "seven"
  // 输出："neven"
  // 解释：将 "seven" 变成回文字符串的最小操作次数为 1 ，修改 1
  // 次得到的字典序最小回文字符串是 "neven" 。
  s = "seven";
  EXPECT_EQ(solution.makeSmallestPalindrome(s), "neven");
}
