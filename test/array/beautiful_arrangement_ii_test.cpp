#include <array/beautiful_arrangement_ii.cpp>

TEST(优美的排列II, constructArray) {
  // 示例 1：
  // 输入：n = 3, k = 1
  // 输出：[1, 2, 3]
  // 解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1
  // 个不同整数：1
  Solution solution;
  int n = 3;
  int k = 1;
  vector<int> res = {1, 2, 3};
  EXPECT_THAT(solution.constructArray(n, k), ::testing::ContainerEq(res));

  // 示例 2：
  // 输入：n = 3, k = 2
  // 输出：[1, 3, 2]
  // 解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2
  // 个不同整数：1 和 2
  int n2 = 3;
  int k2 = 2;
  vector<int> res2 = {1, 3, 2};
  EXPECT_THAT(solution.constructArray(n2, k2), ::testing::ContainerEq(res2));
}
