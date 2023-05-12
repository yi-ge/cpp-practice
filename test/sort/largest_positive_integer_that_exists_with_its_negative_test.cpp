#include <sort/largest_positive_integer_that_exists_with_its_negative.cpp>

TEST(与对应负数同时存在的最大正整数, findMaxK) {
  // 示例 1：
  // 输入：nums = [-1,2,-3,3]
  // 输出：3
  // 解释：3 是数组中唯一一个满足题目要求的 k 。
  Solution solution;
  vector<int> nums = {-1, 2, -3, 3};
  EXPECT_EQ(solution.findMaxK(nums), 3);

  // 示例 2：
  // 输入：nums = [-1,10,6,7,-7,1]
  // 输出：7
  // 解释：数组中存在 1 和 7 对应的负数，7 的值更大。
  nums = {-1, 10, 6, 7, -7, 1};
  EXPECT_EQ(solution.findMaxK(nums), 7);

  // 示例 3：
  // 输入：nums = [-10,8,6,7,-2,-3]
  // 输出：-1
  // 解释：不存在满足题目要求的 k ，返回 -1 。
  nums = {-10, 8, 6, 7, -2, -3};
  EXPECT_EQ(solution.findMaxK(nums), -1);
}
