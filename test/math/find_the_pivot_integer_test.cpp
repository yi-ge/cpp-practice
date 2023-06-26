#include <math/find_the_pivot_integer.cpp>

TEST(找出中枢整数, pivotInteger) {
  Solution solution;
  // 示例 1：
  // 输入：n = 8
  // 输出：6
  // 解释：6 是中枢整数，因为 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21 。
  int n = 8;
  EXPECT_EQ(solution.pivotInteger(n), 6);

  // 示例 2：
  // 输入：n = 1
  // 输出：1
  // 解释：1 是中枢整数，因为 1 = 1 。
  n = 1;
  EXPECT_EQ(solution.pivotInteger(n), 1);

  // 示例 3：
  // 输入：n = 4
  // 输出：-1
  // 解释：可以证明不存在满足题目要求的整数。
  n = 4;
  EXPECT_EQ(solution.pivotInteger(n), -1);
}
