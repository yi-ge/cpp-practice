#include <array/maximum_fruits_harvested_after_at_most_k_steps.cpp>

TEST(摘水果, maxTotalFruits) {
  // 示例 1：
  // 输入：fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
  // 输出：9
  // 解释：
  // 最佳路线为：
  // - 向右移动到位置 6 ，摘到 3 个水果
  // - 向右移动到位置 8 ，摘到 6 个水果
  // 移动 3 步，共摘到 3 + 6 = 9 个水果
  Solution solution;
  vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
  int startPos = 5;
  int k = 4;
  EXPECT_EQ(solution.maxTotalFruits(fruits, startPos, k), 9);

  // 示例 2：
  // 输入：fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
  // 输出：14
  // 解释：
  // 可以移动最多 k = 4 步，所以无法到达位置 0 和位置 10 。
  // 最佳路线为：
  // - 在初始位置 5 ，摘到 7 个水果
  // - 向左移动到位置 4 ，摘到 1 个水果
  // - 向右移动到位置 6 ，摘到 2 个水果
  // - 向右移动到位置 7 ，摘到 4 个水果
  // 移动 1 + 3 = 4 步，共摘到 7 + 1 + 2 + 4 = 14 个水果
  fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
  startPos = 5;
  k = 4;
  EXPECT_EQ(solution.maxTotalFruits(fruits, startPos, k), 14);

  // 示例 3：
  // 输入：fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
  // 输出：0
  // 解释：
  // 最多可以移动 k = 2 步，无法到达任一有水果的地方
  fruits = {{0, 3}, {6, 4}, {8, 5}};
  startPos = 3;
  k = 2;
  EXPECT_EQ(solution.maxTotalFruits(fruits, startPos, k), 0);
}
