#include <sort/greatest_sum_divisible_by_three.cpp>

TEST(可被三整除的最大和, maxSumDivThree) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [3,6,5,1,8]
  // 输出：18
  // 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
  vector<int> nums = {3, 6, 5, 1, 8};
  EXPECT_EQ(solution.maxSumDivThree(nums), 18);

  // 示例 2：
  // 输入：nums = [4]
  // 输出：0
  // 解释：4 不能被 3 整除，所以无法选出数字，返回 0。
  nums = {4};
  EXPECT_EQ(solution.maxSumDivThree(nums), 0);

  // 示例 3：
  // 输入：nums = [1,2,3,4,4]
  // 输出：12
  // 解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
  nums = {1, 2, 3, 4, 4};
  EXPECT_EQ(solution.maxSumDivThree(nums), 12);
}
