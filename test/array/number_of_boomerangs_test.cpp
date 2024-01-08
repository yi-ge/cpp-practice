#include <array/number_of_boomerangs.cpp>

TEST(回旋镖的数量, numberOfBoomerangs) {
  Solution solution;
  // 示例 1：
  // 输入：points = [[0,0],[1,0],[2,0]]
  // 输出：2
  // 解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
  vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 2);

  // 示例 2：
  // 输入：points = [[1,1],[2,2],[3,3]]
  // 输出：2
  vector<vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(solution.numberOfBoomerangs(points2), 2);

  // 示例 3：
  // 输入：points = [[1,1]]
  // 输出：0
  vector<vector<int>> points3 = {{1, 1}};
  EXPECT_EQ(solution.numberOfBoomerangs(points3), 0);
}
