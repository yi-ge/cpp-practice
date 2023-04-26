#include <array/maximum_sum_of_two_non_overlapping_subarrays.cpp>

TEST(两个非重叠子数组的最大和, maxSumTwoNoOverlap) {
  // 示例 1：
  // 输入：nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
  // 输出：20
  // 解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
  Solution solution;
  vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
  int firstLen = 1;
  int secondLen = 2;
  EXPECT_EQ(solution.maxSumTwoNoOverlap(nums, firstLen, secondLen), 20);

  // 示例 2：
  // 输入：nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
  // 输出：29
  // 解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
  nums = {3, 8, 1, 3, 2, 1, 8, 9, 0};
  firstLen = 3;
  secondLen = 2;
  EXPECT_EQ(solution.maxSumTwoNoOverlap(nums, firstLen, secondLen), 29);

  // 示例 3：
  // 输入：nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
  // 输出：31
  // 解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
  nums = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8};
  firstLen = 4;
  secondLen = 3;
  EXPECT_EQ(solution.maxSumTwoNoOverlap(nums, firstLen, secondLen), 31);
}
