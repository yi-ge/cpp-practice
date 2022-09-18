#include <search/making_a_large_island.cpp>

TEST(最大人工岛, largestIsland) {
  // 示例 1:
  // 输入: grid = [[1, 0], [0, 1]]
  // 输出: 3
  // 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
  Solution solution;
  vector<vector<int>> grid = {{1, 0}, {0, 1}};
  EXPECT_EQ(solution.largestIsland(grid), 3);

  // 示例 2:
  // 输入: grid = [[1, 1], [1, 0]]
  // 输出: 4
  // 解释: 将一格0变成1，岛屿的面积扩大为 4。
  vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
  EXPECT_EQ(solution.largestIsland(grid2), 4);

  // 示例 3:
  // 输入: grid = [[1, 1], [1, 1]]
  // 输出: 4
  // 解释: 没有0可以让我们变成1，面积依然为 4。
  vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
  EXPECT_EQ(solution.largestIsland(grid3), 4);
}
