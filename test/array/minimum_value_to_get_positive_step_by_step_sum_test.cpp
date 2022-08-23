#include <array/minimum_value_to_get_positive_step_by_step_sum.cpp>

TEST(逐步求和得到正数的最小值, minStartValue)
{
  // 示例 1：
  // 输入：nums = [-3,2,-3,4,2]
  // 输出：5
  // 解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
  //                 累加求和
  //                 startValue = 4 | startValue = 5 | nums
  //                   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  //                   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  //                   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  //                   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  //                   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
  Solution solution;
  vector<int> nums = {-3, 2, -3, 4, 2};
  EXPECT_EQ(solution.minStartValue(nums), 5);

  // 示例 2：
  // 输入：nums = [1,2]
  // 输出：1
  // 解释：最小的 startValue 需要是正数。
  vector<int> nums2 = {1, 2};
  EXPECT_EQ(solution.minStartValue(nums2), 1);

  // 示例 3：
  // 输入：nums = [1,-2,-3]
  // 输出：5
  vector<int> nums3 = {1, -2, -3};
  EXPECT_EQ(solution.minStartValue(nums3), 5);
}
