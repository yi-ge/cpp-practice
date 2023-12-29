#include <sort/buy_two_chocolates.cpp>

TEST(购买两块巧克力, buyChoco) {
  Solution solution;
  // 示例 1：
  // 输入：prices = [1,2,2], money = 3
  // 输出：0
  // 解释：分别购买价格为 1 和 2 的巧克力。你剩下 3 - 3 = 0 块钱。所以我们返回 0
  vector<int> prices = {1, 2, 2};
  int money = 3;
  EXPECT_EQ(solution.buyChoco(prices, money), 0);

  // 示例 2：
  // 输入：prices = [3,2,3], money = 3
  // 输出：3
  // 解释：购买任意 2 块巧克力都会超过你拥有的钱数，所以我们返回 3 。
  prices = {3, 2, 3};
  money = 3;
  EXPECT_EQ(solution.buyChoco(prices, money), 3);
}
