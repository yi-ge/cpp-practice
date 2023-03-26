#include <array/find_subarrays_with_equal_sum.cpp>

TEST(和相等的子数组, findSubarrays) {
  // 示例 1：
  // 输入：nums = [4,2,4]
  // 输出：true
  // 解释：元素为 [4,2] 和 [2,4] 的子数组有相同的和 6 。
  Solution solution1;
  std::vector<int> nums1 = {4, 2, 4};
  EXPECT_TRUE(solution1.findSubarrays(nums1));

  // 示例 2：
  // 输入：nums = [1,2,3,4,5]
  // 输出：false
  // 解释：没有长度为 2 的两个子数组和相等。
  Solution solution2;
  std::vector<int> nums2 = {1, 2, 3, 4, 5};
  EXPECT_FALSE(solution2.findSubarrays(nums2));

  // 示例 3：
  // 输入：nums = [0,0,0]
  // 输出：true
  // 解释：子数组 [nums[0],nums[1]] 和 [nums[1],nums[2]] 的和相等，都为 0 。
  // 注意即使子数组的元素相同，这两个子数组也视为不相同的子数组，因为它们在原数组中的起始位置不同。
  Solution solution3;
  std::vector<int> nums3 = {0, 0, 0};
  EXPECT_TRUE(solution3.findSubarrays(nums3));

  Solution solution4;
  std::vector<int> nums4 = {0};
  EXPECT_FALSE(solution4.findSubarrays(nums4));
}
