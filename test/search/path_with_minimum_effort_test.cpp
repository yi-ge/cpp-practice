#include <search/path_with_minimum_effort.cpp>

TEST(最小体力消耗路径, minimumEffortPath) {
  Solution solution;
  // 示例 1：
  // 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
  // 输出：2
  // 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
  // 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  EXPECT_EQ(solution.minimumEffortPath(heights), 2);

  // 示例 2：
  // 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
  // 输出：1
  // 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5]
  // 更优。
  vector<vector<int>> heights2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  EXPECT_EQ(solution.minimumEffortPath(heights2), 1);

  // 示例 3：
  // 输入：heights =
  // [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]] 输出：0
  // 解释：上图所示路径不需要消耗任何体力。
  vector<vector<int>> heights3 = {{1, 2, 1, 1, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 1, 1, 2, 1}};
  EXPECT_EQ(solution.minimumEffortPath(heights3), 0);
}
