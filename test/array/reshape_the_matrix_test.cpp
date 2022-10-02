#include <array/reshape_the_matrix.cpp>
TEST(重塑矩阵, matrixReshape) {
  // 示例 1：
  // 输入：mat = [[1,2],[3,4]], r = 1, c = 4
  // 输出：[[1,2,3,4]]
  Solution solution;
  vector<vector<int>> mat = {{1, 2}, {3, 4}};
  vector<vector<int>> res = {{1, 2, 3, 4}};
  EXPECT_EQ(solution.matrixReshape(mat, 1, 4), res);

  // 示例 2：
  // 输入：mat = [[1,2],[3,4]], r = 2, c = 4
  // 输出：[[1,2],[3,4]]
  vector<vector<int>> mat2 = {{1, 2}, {3, 4}};
  vector<vector<int>> res2 = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution.matrixReshape(mat2, 2, 4), res2);
}
