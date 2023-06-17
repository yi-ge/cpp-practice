#include <math/can_make_palindrome_from_substring.cpp>

TEST(构建回文串检测, canMakePaliQueries)
{
  Solution solution;
  // 示例：
  // 输入：s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
  // 输出：[true,false,false,true,true]
  // 解释：
  // queries[0] : 子串 = "d"，回文。
  // queries[1] : 子串 = "bc"，不是回文。
  // queries[2] : 子串 = "abcd"，只替换 1 个字符是变不成回文串的。
  // queries[3] : 子串 = "abcd"，可以变成回文的 "abba"。 也可以变成 "baab"，先重新排序变成 "bacd"，然后把 "cd" 替换为 "ab"。
  // queries[4] : 子串 = "abcda"，可以变成回文的 "abcba"。
  string s = "abcda";
  vector<vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
  vector<bool> expected = {true,false,false,true,true};
  EXPECT_EQ(solution.canMakePaliQueries (s, queries), expected);
}
