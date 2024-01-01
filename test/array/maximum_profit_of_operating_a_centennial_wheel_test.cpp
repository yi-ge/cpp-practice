#include <array/maximum_profit_of_operating_a_centennial_wheel.cpp>

TEST(经营摩天轮的最大利润, minOperationsMaxProfit) {
  Solution solution;
  // 示例 1：
  // 输入：customers = [8,3], boardingCost = 5, runningCost = 6
  // 输出：3
  // 解释：座舱上标注的数字是该座舱的当前游客数。
  // 1. 8 位游客抵达，4 位登舱，4 位等待下一舱，摩天轮轮转。当前利润为 4 * $5 -
  // 1 * $6 = $14 。
  // 2. 3 位游客抵达，4 位在等待的游客登舱，其他 3
  // 位等待，摩天轮轮转。当前利润为 8 * $5 - 2 * $6 = $28 。
  // 3. 最后 3 位游客登舱，摩天轮轮转。当前利润为 11 * $5 - 3 * $6 = $37 。
  // 轮转 3 次得到最大利润，最大利润为 $37 。
  vector<int> customers = {8, 3};
  int boardingCost = 5;
  int runningCost = 6;
  EXPECT_EQ(
      solution.minOperationsMaxProfit(customers, boardingCost, runningCost), 3);

  // 示例 2：
  // 输入：customers = [10,9,6], boardingCost = 6, runningCost = 4
  // 输出：7
  // 解释：
  // 1. 10 位游客抵达，4 位登舱，6 位等待下一舱，摩天轮轮转。当前利润为 4 * $6 -
  // 1 * $4 = $20 。
  // 2. 9 位游客抵达，4 位登舱，11 位等待（2 位是先前就在等待的，9
  // 位新加入等待的），摩天轮轮转。当前利润为 8 * $6 - 2 * $4 = $40 。
  // 3. 最后 6 位游客抵达，4 位登舱，13 位等待，摩天轮轮转。当前利润为 12 * $6 -
  // 3 * $4 = $60 。
  // 4. 4 位登舱，9 位等待，摩天轮轮转。当前利润为 * $6 - 4 * $4 = $80 。
  // 5. 4 位登舱，5 位等待，摩天轮轮转。当前利润为 20 * $6 - 5 * $4 = $100 。
  // 6. 4 位登舱，1 位等待，摩天轮轮转。当前利润为 24 * $6 - 6 * $4 = $120 。
  // 7. 1 位登舱，摩天轮轮转。当前利润为 25 * $6 - 7 * $4 = $122 。
  // 轮转 7 次得到最大利润，最大利润为$122 。
  customers = {10, 9, 6};
  boardingCost = 6;
  runningCost = 4;
  EXPECT_EQ(
      solution.minOperationsMaxProfit(customers, boardingCost, runningCost), 7);

  // 示例 3：
  // 输入：customers = [3,4,0,5,1], boardingCost = 1, runningCost = 92
  // 输出：-1
  // 解释：
  // 1. 3 位游客抵达，3 位登舱，0 位等待，摩天轮轮转。当前利润为 3 * $1 - 1 *
  // $92 = -$89 。
  // 2. 4 位游客抵达，4 位登舱，0 位等待，摩天轮轮转。当前利润为 7 * $1 - 2 *
  // $92 = -$177 。
  // 3. 0 位游客抵达，0 位登舱，0 位等待，摩天轮轮转。当前利润为 7 * $1 - 3 *
  // $92 = -$269 。
  // 4. 5 位游客抵达，4 位登舱，1 位等待，摩天轮轮转。当前利润为 11 * $1 - 4 *
  // $92 = -$357 。
  // 5. 1 位游客抵达，2 位登舱，0 位等待，摩天轮轮转。当前利润为 13 * $1 - 5 *
  // $92 = -$447 。 利润永不为正，所以返回 -1 。
  customers = {3, 4, 0, 5, 1};
  boardingCost = 1;
  runningCost = 92;
  EXPECT_EQ(
      solution.minOperationsMaxProfit(customers, boardingCost, runningCost),
      -1);
}
