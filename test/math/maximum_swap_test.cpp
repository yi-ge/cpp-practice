#include <math/maximum_swap.cpp>

TEST(最大交换, maximumSwap) {
  // 示例 1 :
  // 输入: 2736
  // 输出: 7236
  // 解释: 交换数字2和数字7。
  Solution solution;
  EXPECT_EQ(solution.maximumSwap(2736), 7236);

  // 示例 2 :
  // 输入: 9973
  // 输出: 9973
  // 解释: 不需要交换。
  EXPECT_EQ(solution.maximumSwap(9973), 9973);

  EXPECT_EQ(solution.maximumSwap(9), 9);
}
