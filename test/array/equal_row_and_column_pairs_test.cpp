#include <array/equal_row_and_column_pairs.cpp>

TEST(相等行列对, equalPairs) {
  Solution solution;
  // 示例 1：
  // 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
  // 输出：1
  // 解释：存在一对相等行列对：
  // - (第 2 行，第 1 列)：[2,7,7]
  vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  EXPECT_EQ(solution.equalPairs(grid), 1);

  // 示例 2：
  // 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
  // 输出：3
  // 解释：存在三对相等行列对：
  // - (第 0 行，第 0 列)：[3,1,2,2]
  // - (第 2 行, 第 2 列)：[2,4,2,2]
  // - (第 3 行, 第 2 列)：[2,4,2,2]
  grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  EXPECT_EQ(solution.equalPairs(grid), 3);
}
