#include <math/smallest_even_multiple.cpp>

TEST(最小偶倍数, smallestEvenMultiple) {
  // 示例 1：
  // 输入：n = 5
  // 输出：10
  // 解释：5 和 2 的最小公倍数是 10 。
  Solution solution;
  int n = 5;
  EXPECT_EQ(solution.smallestEvenMultiple(n), 10);

  // 示例 2：
  // 输入：n = 6
  // 输出：6
  // 解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
  n = 6;
  EXPECT_EQ(solution.smallestEvenMultiple(n), 6);
}
