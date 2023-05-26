#include <cmath>
#include <graphs/frog_position_after_t_seconds.cpp>

TEST(T秒后青蛙的位置, frogPosition) {
  Solution solution;
  int n = 7;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
  int t = 2;
  int target = 4;
  double eps = 1e-5;
  double ans = solution.frogPosition(n, edges, t, target);
  ASSERT_TRUE(abs(ans - 0.16666666666666666) <= eps);

  // 示例 2：
  // 输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target =
  // 7 输出：0.3333333333333333 解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1
  // 起跳，有 1/3 = 0.3333333333333333 的概率能够 1 秒 后跳到顶点 7 。
  t = 1;
  target = 7;
  ans = solution.frogPosition(n, edges, t, target);
  ASSERT_TRUE(abs(ans - 0.3333333333333333) <= eps);
}
