#include <graphs/flower_planting_with_no_adjacent.cpp>

TEST(不邻接植花, gardenNoAdj) {
  // 示例 1：
  // 输入：n = 3, paths = [[1,2],[2,3],[3,1]]
  // 输出：[1,2,3]
  // 解释：
  // 花园 1 和 2 花的种类不同。
  // 花园 2 和 3 花的种类不同。
  // 花园 3 和 1 花的种类不同。
  // 因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2]
  // 和 [3,2,1]
  Solution solution;
  int n = 3;
  vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
  vector<int> result = solution.gardenNoAdj(n, paths);
  vector<int> expect = {1, 2, 3};
  EXPECT_EQ(result, expect);

  // 示例 2：
  // 输入：n = 4, paths = [[1,2],[3,4]]
  // 输出：[1,2,1,2]
  n = 4;
  paths = {{1, 2}, {3, 4}};
  result = solution.gardenNoAdj(n, paths);
  expect = {1, 2, 1, 2};
  EXPECT_EQ(result, expect);

  // 示例 3：
  // 输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
  // 输出：[1,2,3,4]
  n = 4;
  paths = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
  result = solution.gardenNoAdj(n, paths);
  expect = {1, 2, 3, 4};
  EXPECT_EQ(result, expect);
}
