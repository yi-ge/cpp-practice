#include <sort/maximum_tastiness_of_candy_basket.cpp>

TEST(礼盒的最大甜蜜度, maximumTastiness) {
  Solution solution;
  // 示例 1：
  // 输入：price = [13,5,1,8,21,2], k = 3
  // 输出：8
  // 解释：选出价格分别为 [13,5,21] 的三类糖果。
  // 礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
  // 可以证明能够取得的最大甜蜜度就是 8 。
  vector<int> price = {13, 5, 1, 8, 21, 2};
  int k = 3;
  EXPECT_EQ(solution.maximumTastiness(price, k), 8);

  // 示例 2：
  // 输入：price = [1,3,1], k = 2
  // 输出：2
  // 解释：选出价格分别为 [1,3] 的两类糖果。
  // 礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
  // 可以证明能够取得的最大甜蜜度就是 2 。
  price = {1, 3, 1};
  k = 2;
  EXPECT_EQ(solution.maximumTastiness(price, k), 2);

  // 示例 3：
  // 输入：price = [7,7,7,7], k = 2
  // 输出：0
  // 解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
  price = {7, 7, 7, 7};
  k = 2;
  EXPECT_EQ(solution.maximumTastiness(price, k), 0);
}
