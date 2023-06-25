#include <math/circle_and_rectangle_overlapping.cpp>

TEST(圆和矩形是否有重叠, checkOverlap) {
  Solution solution;
  // 示例 1 ：
  // 输入：radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
  // 输出：true
  // 解释：圆和矩形存在公共点 (1,0) 。
  int radius = 1;
  int xCenter = 0;
  int yCenter = 0;
  int x1 = 1;
  int y1 = -1;
  int x2 = 3;
  int y2 = 1;
  EXPECT_TRUE(solution.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));

  // 示例 2 ：
  // 输入：radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 =
  // -1 输出：false
  radius = 1;
  xCenter = 1;
  yCenter = 1;
  x1 = 1;
  y1 = -3;
  x2 = 2;
  y2 = -1;
  EXPECT_FALSE(solution.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));

  // 示例 3 ：
  // 输入：radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
  // 输出：true
  radius = 1;
  xCenter = 0;
  yCenter = 0;
  x1 = -1;
  y1 = 0;
  x2 = 0;
  y2 = 1;
  EXPECT_TRUE(solution.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));
}
