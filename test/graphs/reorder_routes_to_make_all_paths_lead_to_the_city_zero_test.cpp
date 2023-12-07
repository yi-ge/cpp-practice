#include <graphs/reorder_routes_to_make_all_paths_lead_to_the_city_zero.cpp>

TEST(重新规划路线, minReorder) {
  Solution solution;
  // 示例 1：
  // 输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
  // 输出：3
  // 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  EXPECT_EQ(solution.minReorder(n, connections), 3);

  // 示例 2：
  // 输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
  // 输出：2
  // 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
  n = 5;
  connections = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
  EXPECT_EQ(solution.minReorder(n, connections), 2);
  // 示例 3：
  // 输入：n = 3, connections = [[1,0],[2,0]]
  // 输出：0
  n = 3;
  connections = {{1, 0}, {2, 0}};
  EXPECT_EQ(solution.minReorder(n, connections), 0);
}
