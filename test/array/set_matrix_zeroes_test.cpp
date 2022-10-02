#include <array/set_matrix_zeroes.cpp>
TEST(矩阵置零, setZeroes) {
  // 示例 1：
  // 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
  // 输出：[[1,0,1],[0,0,0],[1,0,1]]
  Solution solution;
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> result = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  solution.setZeroes(matrix);
  EXPECT_EQ(matrix, result);

  // 示例 2：
  // 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
  // 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
  vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> result2 = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  solution.setZeroes(matrix2);
  EXPECT_EQ(matrix2, result2);
}
