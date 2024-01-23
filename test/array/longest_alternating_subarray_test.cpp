#include <array/longest_alternating_subarray.cpp>

TEST(最长交替子数组, alternatingSubarray) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [2,3,4,3,4]
  // 输出：4
  // 解释：交替子数组有 [3,4] ，[3,4,3] 和 [3,4,3,4] 。最长的子数组为 [3,4,3,4]
  // ，长度为4 。
  vector<int> nums = {2, 3, 4, 3, 4};
  EXPECT_EQ(solution.alternatingSubarray(nums), 4);

  // 示例 2：
  // 输入：nums = [4,5,6]
  // 输出：2
  // 解释：[4,5] 和 [5,6] 是仅有的两个交替子数组。它们长度都为 2 。
  nums = {4, 5, 6};
  EXPECT_EQ(solution.alternatingSubarray(nums), 2);
}
