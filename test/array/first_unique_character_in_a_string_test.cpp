#include <array/first_unique_character_in_a_string.cpp>

TEST(字符串中的第一个唯一字符, firstUniqChar) {
  // 示例 1：
  // 输入: s = "leetcode"
  // 输出: 0
  Solution solution;
  string s = "leetcode";
  EXPECT_EQ(solution.firstUniqChar(s), 0);

  // 示例 2:
  // 输入: s = "loveleetcode"
  // 输出: 2
  string s2 = "loveleetcode";
  EXPECT_EQ(solution.firstUniqChar(s2), 2);

  // 示例 3:
  // 输入: s = "aabb"
  // 输出: -1
  string s3 = "aabb";
  EXPECT_EQ(solution.firstUniqChar(s3), -1);
}
