#include <stack/longest_valid_parentheses.cpp>

TEST(最长有效括号, longestValidParentheses)
{
  // 示例 1：
  // 输入：s = "(()"
  // 输出：2
  // 解释：最长有效括号子串是 "()"
  Solution solution;
  string s = "(()";
  EXPECT_EQ(solution.longestValidParentheses(s), 2);

  // 示例 2：
  // 输入：s = ")()())"
  // 输出：4
  // 解释：最长有效括号子串是 "()()"
  string s1 = ")()())";
  EXPECT_EQ(solution.longestValidParentheses(s1), 4);

  // 示例 3：
  // 输入：s = ""
  // 输出：0
  string s2 = "";
  EXPECT_EQ(solution.longestValidParentheses(s2), 0);
}
