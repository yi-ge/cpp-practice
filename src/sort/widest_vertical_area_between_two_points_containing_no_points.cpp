// 两点之间不包含任何点的最宽垂直区域
// https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points
// INLINE
// ../../images/sort/widest_vertical_area_between_two_points_containing_no_points.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    // 将点按照横坐标从小到大排序
    sort(points.begin(), points.end());
    int maxX = 0; // 最大宽度初始为0
    // 遍历每两个相邻的点，计算它们之间的横坐标差，更新最大宽度
    for (int i = 1; i < points.size(); i++) {
      maxX = max(points[i][0] - points[i - 1][0], maxX);
    }
    return maxX; // 返回最大宽度
  }
};