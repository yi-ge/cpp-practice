#include <map/smallest_integer_divisible_by_k.cpp>

TEST(可被K整除的最小整数, smallestRepunitDivByK) {
  // 示例 1：
  // 输入：k = 1
  // 输出：1
  // 解释：最小的答案是 n = 1，其长度为 1。
  Solution solution;
  int k = 1;
  EXPECT_EQ(solution.smallestRepunitDivByK(k), 1);

  // 示例 2：
  // 输入：k = 2
  // 输出：-1
  // 解释：不存在可被 2 整除的正整数 n 。
  k = 2;
  EXPECT_EQ(solution.smallestRepunitDivByK(k), -1);

  // 示例 3：
  // 输入：k = 3
  // 输出：3
  // 解释：最小的答案是 n = 111，其长度为 3。
  k = 3;
  EXPECT_EQ(solution.smallestRepunitDivByK(k), 3);
}
