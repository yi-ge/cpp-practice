#include <math/minimum_cost_to_connect_two_groups_of_points.cpp>

TEST(连通两组点的最小成本, connectTwoGroups) {
  Solution solution;
  // 示例 1：
  // 输入：cost = [[15, 96], [36, 2]]
  // 输出：17
  // 解释：连通两组点的最佳方法是：
  // 1--A
  // 2--B
  // 总成本为 17 。
  vector<vector<int>> cost = {{15, 96}, {36, 2}};
  EXPECT_EQ(solution.connectTwoGroups(cost), 17);

  // 示例 2：
  // 输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
  // 输出：4
  // 解释：连通两组点的最佳方法是：
  // 1--A
  // 2--B
  // 2--C
  // 3--A
  // 最小成本为 4 。
  // 请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A
  // ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。
  vector<vector<int>> cost2 = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  EXPECT_EQ(solution.connectTwoGroups(cost2), 4);

  //  示例 3：
  // 输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
  // 输出：10
  vector<vector<int>> cost3 = {
      {2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
  EXPECT_EQ(solution.connectTwoGroups(cost3), 10);
}
