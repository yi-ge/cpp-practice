#include <string/construct_string_with_repeat_limit.cpp>

TEST(构造限制重复的字符串, repeatLimitedString) {
  Solution solution;
  // 示例 1：
  // 输入：s = "cczazcc", repeatLimit = 3
  // 输出："zzcccac"
  // 解释：使用 s 中的所有字符来构造 repeatLimitedString "zzcccac"。
  // 字母 'a' 连续出现至多 1 次。
  // 字母 'c' 连续出现至多 3 次。
  // 字母 'z' 连续出现至多 2 次。
  // 因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的
  // repeatLimitedString 。 该字符串是字典序最大的 repeatLimitedString
  // ，所以返回 "zzcccac" 。 注意，尽管 "zzcccca" 字典序更大，但字母 'c'
  // 连续出现超过 3 次，所以它不是一个有效的 repeatLimitedString 。
  string s = "cczazcc";
  int repeatLimit = 3;
  EXPECT_EQ(solution.repeatLimitedString(s, repeatLimit), "zzcccac");

  // 示例 2：
  // 输入：s = "aababab", repeatLimit = 2
  // 输出："bbabaa"
  // 使用 s 中的一些字符来构造 repeatLimitedString "bbabaa"。
  // 解释：
  // 字母 'a' 连续出现至多 2 次。
  // 字母 'b' 连续出现至多 2 次。
  // 因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的
  // repeatLimitedString 。 该字符串是字典序最大的 repeatLimitedString
  // ，所以返回 "bbabaa" 。 注意，尽管 "bbabaaa" 字典序更大，但字母 'a'
  // 连续出现超过 2 次，所以它不是一个有效的 repeatLimitedString 。
  s = "aababab";
  repeatLimit = 2;
  EXPECT_EQ(solution.repeatLimitedString(s, repeatLimit), "bbabaa");
}
