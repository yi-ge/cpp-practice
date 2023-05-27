#include <search/shortest_path_in_binary_matrix.cpp>

TEST(二进制矩阵中的最短路径, shortestPathBinaryMatrix) {
  Solution solution;
  // 示例 1：
  // 输入：grid = [[0,1],[1,0]]
  // 输出：2
  vector<vector<int>> grid = {{0, 1}, {1, 0}};
  EXPECT_EQ(solution.shortestPathBinaryMatrix(grid), 2);

  // 示例 2：
  // 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
  // 输出：4
  grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(solution.shortestPathBinaryMatrix(grid), 4);

  // 示例 3：
  // 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
  // 输出：-1
  grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(solution.shortestPathBinaryMatrix(grid), -1);
}
