#include <other/minimum_additions_to_make_valid_string.cpp>

TEST(构造有效字符串的最少插入数, addMinimum) {
  Solution solution;
  // 示例 1：
  // 输入：word = "b"
  // 输出：2
  // 解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
  string word = "b";
  int expected = 2;
  EXPECT_EQ(solution.addMinimum(word), expected);

  // 示例 2：
  // 输入：word = "aaa"
  // 输出：6
  // 解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。
  word = "aaa";
  expected = 6;
  EXPECT_EQ(solution.addMinimum(word), expected);

  // 示例 3：
  // 输入：word = "abc"
  // 输出：0
  // 解释：word 已经是有效字符串，不需要进行修改。
  word = "abc";
  expected = 0;
  EXPECT_EQ(solution.addMinimum(word), expected);
}
