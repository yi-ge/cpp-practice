#include <map/ransom_note.cpp>

TEST(赎金信, canConstruct) {
  // 示例 1：
  // 输入：ransomNote = "a", magazine = "b"
  // 输出：false
  Solution solution;
  string ransomNote = "a";
  string magazine = "b";
  EXPECT_FALSE(solution.canConstruct(ransomNote, magazine));

  // 示例 2：
  // 输入：ransomNote = "aa", magazine = "ab"
  // 输出：false
  string ransomNote2 = "aa";
  string magazine2 = "ab";
  EXPECT_FALSE(solution.canConstruct(ransomNote2, magazine2));

  // 示例 3：
  // 输入：ransomNote = "aa", magazine = "aab"
  // 输出：true
  string ransomNote3 = "aa";
  string magazine3 = "aab";
  EXPECT_TRUE(solution.canConstruct(ransomNote3, magazine3));

  string ransomNote4 = "aabb";
  string magazine4 = "aab";
  EXPECT_FALSE(solution.canConstruct(ransomNote4, magazine4));
}
