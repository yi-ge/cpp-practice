#include <graphs/minimize_the_total_price_of_the_trips.cpp>

TEST(最小化旅行的价格总和, minimumTotalPrice) {
  Solution solution;
  // 示例 1：
  // 输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips =
  // [[0,3],[2,1],[2,3]] 输出：23 解释： 上图表示将节点 2
  // 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 、2 和 3
  // 并使其价格减半后的树。 第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 +
  // 2 + 3 = 6 。 第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。 第
  // 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 = 10 。
  // 所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实现的最小答案。
  vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}};
  vector<int> price1 = {2, 2, 10, 6};
  vector<vector<int>> trips1 = {{0, 3}, {2, 1}, {2, 3}};
  EXPECT_EQ(solution.minimumTotalPrice(4, edges1, price1, trips1), 23);

  // 示例 2：
  // 输入：n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
  // 输出：1
  // 解释：
  // 上图表示将节点 0
  // 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0
  // 并使其价格减半后的树。 第 1 次旅行，选择路径 [0] 。路径的价格总和为 1 。
  // 所有旅行的价格总和为 1 。可以证明，1 是可以实现的最小答案。
  vector<vector<int>> edges2 = {{0, 1}};
  vector<int> price2 = {2, 2};
  vector<vector<int>> trips2 = {{0, 0}};
  EXPECT_EQ(solution.minimumTotalPrice(2, edges2, price2, trips2), 1);
}
