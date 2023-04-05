#include <math/number_of_common_factors.cpp>

TEST(公因子的数目, commonFactors) {
  // 示例 1：
  // 输入：a = 12, b = 6
  // 输出：4
  // 解释：12 和 6 的公因子是 1、2、3、6 。
  Solution solution;
  int a = 12, b = 6;
  EXPECT_EQ(solution.commonFactors(a, b), 4);

  // 示例 2：
  // 输入：a = 25, b = 30
  // 输出：2
  // 解释：25 和 30 的公因子是 1、5 。
  a = 25, b = 30;
  EXPECT_EQ(solution.commonFactors(a, b), 2);
}
