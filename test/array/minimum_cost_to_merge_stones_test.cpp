#include <array/minimum_cost_to_merge_stones.cpp>

TEST(合并石头的最低成本, mergeStones) {
  // 示例 1：
  // 输入：stones = [3,2,4,1], K = 2
  // 输出：20
  // 解释：
  // 从 [3, 2, 4, 1] 开始。
  // 合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
  // 合并 [4, 1]，成本为 5，剩下 [5, 5]。
  // 合并 [5, 5]，成本为 10，剩下 [10]。
  // 总成本 20，这是可能的最小值。
  Solution solution;
  std::vector<int> stones1 = {3, 2, 4, 1};
  int K1 = 2;
  int expected1 = 20;
  EXPECT_EQ(solution.mergeStones(stones1, K1), expected1);

  // 示例 2：
  // 输入：stones = [3,2,4,1], K = 3
  // 输出：-1
  // 解释：任何合并操作后，都会剩下 2
  // 堆，我们无法再进行合并。所以这项任务是不可能完成的。
  std::vector<int> stones2 = {3, 2, 4, 1};
  int K2 = 3;
  int expected2 = -1;
  EXPECT_EQ(solution.mergeStones(stones2, K2), expected2);

  // 示例 3：
  // 输入：stones = [3,5,1,2,6], K = 3
  // 输出：25
  // 解释：
  // 从 [3, 5, 1, 2, 6] 开始。
  // 合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
  // 合并 [3, 8, 6]，成本为 17，剩下 [17]。
  // 总成本 25，这是可能的最小值。
  std::vector<int> stones3 = {3, 5, 1, 2, 6};
  int K3 = 3;
  int expected3 = 25;
  EXPECT_EQ(solution.mergeStones(stones3, K3), expected3);
}
