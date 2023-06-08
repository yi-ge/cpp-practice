#include <other/tiling_a_rectangle_with_the_fewest_squares.cpp>

TEST(铺瓷砖, tilingRectangle) {
  Solution solution;
  // 示例 1：
  // 输入：n = 2, m = 3
  // 输出：3
  // 解释：3 块地砖就可以铺满卧室。
  //      2 块 1x1 地砖
  //      1 块 2x2 地砖
  int n = 2;
  int m = 3;
  EXPECT_EQ(solution.tilingRectangle(n, m), 3);

  // 示例 2：
  // 输入：n = 5, m = 8
  // 输出：5
  n = 5;
  m = 8;
  EXPECT_EQ(solution.tilingRectangle(n, m), 5);

  // 示例 3：
  // 输入：n = 11, m = 13
  // 输出：6
  n = 11;
  m = 13;
  EXPECT_EQ(solution.tilingRectangle(n, m), 6);
}
