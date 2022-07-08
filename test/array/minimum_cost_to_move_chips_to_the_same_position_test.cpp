#include <array/minimum_cost_to_move_chips_to_the_same_position.cpp>

TEST(玩筹码, minCostToMoveChips)
{
  // 示例 1：
  // 输入：position = [1,2,3]
  // 输出：1
  // 解释：第一步:将位置3的筹码移动到位置1，成本为0。
  // 第二步:将位置2的筹码移动到位置1，成本= 1。
  // 总成本是1。

  // 示例 2：
  // 输入：position = [2,2,2,3,3]
  // 输出：2
  // 解释：我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。

  // 示例 3:
  // 输入：position = [1,1000000000]
  // 输出：1

  Solution solution;
  vector<int> position = {1, 2, 3};
  EXPECT_EQ(solution.minCostToMoveChips(position), 1);

  vector<int> position2 = {2, 2, 2, 3, 3};
  EXPECT_EQ(solution.minCostToMoveChips(position2), 2);

  vector<int> position3 = {1, 1000000000};
  EXPECT_EQ(solution.minCostToMoveChips(position3), 1);
}
