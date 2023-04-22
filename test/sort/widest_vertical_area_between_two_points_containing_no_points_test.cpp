#include <sort/widest_vertical_area_between_two_points_containing_no_points.cpp>

TEST(两点之间不包含任何点的最宽垂直区域, maxWidthOfVerticalArea) {
  // 示例 1：
  // 输入：points = [[8,7],[9,9],[7,4],[9,7]]
  // 输出：1
  // 解释：红色区域和蓝色区域都是最优区域。

  Solution solution;
  vector<vector<int>> points1{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
  EXPECT_EQ(solution.maxWidthOfVerticalArea(points1), 1);

  // 示例 2：
  // 输入：points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
  // 输出：3

  vector<vector<int>> points2{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
  EXPECT_EQ(solution.maxWidthOfVerticalArea(points2), 3);
}
