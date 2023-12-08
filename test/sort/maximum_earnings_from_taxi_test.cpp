#include <sort/maximum_earnings_from_taxi.cpp>

TEST(出租车的最大盈利, maxTaxiEarnings) {
  Solution solution;
  // 示例 1：
  // 输入：n = 5, rides = [[2,5,4],[1,5,1]]
  // 输出：7
  // 解释：我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。
  int n = 5;
  vector<vector<int>> rides = {{2, 5, 4}, {1, 5, 1}};
  EXPECT_EQ(solution.maxTaxiEarnings(n, rides), 7);

  // 示例 2：
  // 输入：n = 20, rides =
  // [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]] 输出：20
  // 解释：我们可以接以下乘客的订单：
  // - 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
  // - 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
  // - 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
  // 我们总共获得 9 + 5 + 6 = 20 元。
  n = 20;
  rides = {{1, 6, 1},   {3, 10, 2},  {10, 12, 3},
           {11, 12, 2}, {12, 15, 2}, {13, 18, 1}};
  EXPECT_EQ(solution.maxTaxiEarnings(n, rides), 20);
}
