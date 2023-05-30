#include <array/average_value_of_even_numbers_that_are_divisible_by_three.cpp>

TEST(可被三整除的偶数的平均值, averageValue) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [1,3,6,10,12,15]
  // 输出：9
  // 解释：6 和 12 是可以被 3 整除的偶数。(6 + 12) / 2 = 9 。
  vector<int> nums = {1, 3, 6, 10, 12, 15};
  EXPECT_EQ(solution.averageValue(nums), 9);

  // 示例 2：
  // 输入：nums = [1,2,4,7,10]
  // 输出：0
  // 解释：不存在满足题目要求的整数，所以返回 0 。
  nums = {1, 2, 4, 7, 10};
  EXPECT_EQ(solution.averageValue(nums), 0);
}
