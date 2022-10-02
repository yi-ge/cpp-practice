#include <array/pascals_triangle.cpp>

TEST(杨辉三角, generate) {
  // 示例 1:
  // 输入: numRows = 5
  // 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
  Solution solution;
  int numRows = 5;
  vector<vector<int>> res = {
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
  EXPECT_EQ(solution.generate(numRows), res);

  // 示例 2:
  // 输入: numRows = 1
  // 输出: [[1]]
  int numRows2 = 1;
  vector<vector<int>> res2 = {{1}};
  EXPECT_EQ(solution.generate(numRows2), res2);
}
