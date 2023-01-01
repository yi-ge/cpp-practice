#include <map/first_letter_to_appear_twice.cpp>

TEST(第一个出现两次的字母, repeatedCharacter) {
  // 示例 1：
  // 输入：s = "abccbaacz"
  // 输出："c"
  // 解释：
  // 字母 'a' 在下标 0 、5 和 6 处出现。
  // 字母 'b' 在下标 1 和 4 处出现。
  // 字母 'c' 在下标 2 、3 和 7 处出现。
  // 字母 'z' 在下标 8 处出现。
  // 字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c'
  // 第二次出现的下标是最小的。
  Solution solution;
  string s = "abccbaacz";
  EXPECT_EQ(solution.repeatedCharacter(s), 'c');

  // 示例 2：
  // 输入：s = "abcdd"
  // 输出："d"
  // 解释：
  // 只有字母 'd' 出现两次，所以返回 'd' 。
  string s1 = "abcdd";
  EXPECT_EQ(solution.repeatedCharacter(s1), 'd');

  string s2 = "abc";
  EXPECT_EQ(solution.repeatedCharacter(s2), ' ');
}
