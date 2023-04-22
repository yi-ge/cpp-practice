#include <array/longest_arithmetic_subsequence.cpp>

TEST(最长等差数列, longestArithSeqLength) {
  // 示例 1：
  // 输入：nums = [3,6,9,12]
  // 输出：4
  // 解释：
  // 整个数组是公差为 3 的等差数列。
  Solution solution;
  vector<int> nums = {3, 6, 9, 12};
  EXPECT_EQ(solution.longestArithSeqLength(nums), 4);

  // 示例 2：
  // 输入：nums = [9,4,7,2,10]
  // 输出：3
  // 解释：
  // 最长的等差子序列是 [4,7,10]。
  nums = {9, 4, 7, 2, 10};
  EXPECT_EQ(solution.longestArithSeqLength(nums), 3);

  // 示例 3：
  // 输入：nums = [20,1,15,3,10,5,8]
  // 输出：4
  // 解释：
  // 最长的等差子序列是 [20,15,10,5]。
  nums = {20, 1, 15, 3, 10, 5, 8};
  EXPECT_EQ(solution.longestArithSeqLength(nums), 4);
}
