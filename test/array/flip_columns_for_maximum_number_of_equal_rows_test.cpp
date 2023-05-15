#include <array/flip_columns_for_maximum_number_of_equal_rows.cpp>

TEST(按列翻转得到最大值等行数, maxEqualRowsAfterFlips) {
  // 示例 1：
  // 输入：matrix = [[0,1],[1,1]]
  // 输出：1
  // 解释：不进行翻转，有 1 行所有值都相等。
  Solution solution;
  vector<vector<int>> matrix = {{0, 1}, {1, 1}};
  EXPECT_EQ(solution.maxEqualRowsAfterFlips(matrix), 1);

  // 示例 2：
  // 输入：matrix = [[0,1],[1,0]]
  // 输出：2
  // 解释：翻转第一列的值之后，这两行都由相等的值组成。
  matrix = {{0, 1}, {1, 0}};
  EXPECT_EQ(solution.maxEqualRowsAfterFlips(matrix), 2);

  // 示例 3：
  // 输入：matrix = [[0,0,0],[0,0,1],[1,1,0]]
  // 输出：2
  // 解释：翻转前两列的值之后，后两行由相等的值组成。
  matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
  EXPECT_EQ(solution.maxEqualRowsAfterFlips(matrix), 2);
}
