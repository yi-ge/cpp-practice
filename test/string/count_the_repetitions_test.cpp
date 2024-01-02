#include <string/count_the_repetitions.cpp>

TEST(统计重复个数, getMaxRepetitions) {
  Solution solution;
  // 示例 1：
  // 输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
  // 输出：2
  string s1 = "acb";
  int n1 = 4;
  string s2 = "ab";
  int n2 = 2;
  EXPECT_EQ(solution.getMaxRepetitions(s1, n1, s2, n2), 2);

  // 示例 2：
  // 输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
  // 输出：1
  s1 = "acb";
  n1 = 1;
  s2 = "acb";
  n2 = 1;
  EXPECT_EQ(solution.getMaxRepetitions(s1, n1, s2, n2), 1);
}
