#include <math/minimum_cuts_to_divide_a_circle.cpp>

TEST(分割圆的最少切割次数, numberOfCuts) {
  Solution solution;
  // 示例 1：
  // 输入：n = 4
  // 输出：2
  // 解释：
  // 上图展示了切割圆 2 次，得到四等分。
  int n = 4;
  EXPECT_EQ(solution.numberOfCuts(n), 2);

  // 示例 2：
  // 输入：n = 3
  // 输出：3
  // 解释：
  // 最少需要切割 3 次，将圆切成三等分。
  // 少于 3 次切割无法将圆切成大小相等面积相同的 3 等分。
  // 同时可以观察到，第一次切割无法将圆切割开。
  n = 3;
  EXPECT_EQ(solution.numberOfCuts(n), 3);
}
