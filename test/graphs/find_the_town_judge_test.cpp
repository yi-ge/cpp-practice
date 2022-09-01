#include <graphs/find_the_town_judge.cpp>

TEST(找到小镇的法官, findJudge)
{
  // 示例 1：
  // 输入：n = 2, trust = [[1,2]]
  // 输出：2
  Solution solution;
  vector<vector<int>> trust = {{1, 2}};
  EXPECT_EQ(solution.findJudge(2, trust), 2);

  // 示例 2：
  // 输入：n = 3, trust = [[1,3],[2,3]]
  // 输出：3
  vector<vector<int>> trust2 = {{1, 3}, {2, 3}};
  EXPECT_EQ(solution.findJudge(3, trust2), 3);

  // 示例 3：
  // 输入：n = 3, trust = [[1,3],[2,3],[3,1]]
  // 输出：-1
  vector<vector<int>> trust3 = {{1, 3}, {2, 3}, {3, 1}};
  EXPECT_EQ(solution.findJudge(3, trust3), -1);
}
