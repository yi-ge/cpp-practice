#include <array/split_array_largest_sum.cpp>

TEST(分割数组的最大值, splitArray) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [7,2,5,10,8], k = 2
  // 输出：18
  // 解释：
  // 一共有四种方法将 nums 分割为 2 个子数组。
  // 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
  // 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
  vector<int> nums = {7, 2, 5, 10, 8};
  int k = 2;
  EXPECT_EQ(solution.splitArray(nums, k), 18);

  // 示例 2：
  // 输入：nums = [1,2,3,4,5], k = 2
  // 输出：9
  vector<int> nums2 = {1, 2, 3, 4, 5};
  int k2 = 2;
  EXPECT_EQ(solution.splitArray(nums2, k2), 9);

  // 示例 3：
  // 输入：nums = [1,4,4], k = 3
  // 输出：4
  vector<int> nums3 = {1, 4, 4};
  int k3 = 3;
  EXPECT_EQ(solution.splitArray(nums3, k3), 4);
}
