#include <array/partition_array_for_maximum_sum.cpp>

TEST(分隔数组以得到最大和, maxSumAfterPartitioning) {
  // 示例 1：
  // 输入：arr = [1,15,7,9,2,5,10], k = 3
  // 输出：84
  // 解释：数组变为 [15,15,15,9,10,10,10]
  Solution solution;
  vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
  int k = 3;
  EXPECT_EQ(solution.maxSumAfterPartitioning(arr, k), 84);

  // 示例 2：
  // 输入：arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
  // 输出：83
  arr = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
  k = 4;
  EXPECT_EQ(solution.maxSumAfterPartitioning(arr, k), 83);

  // 示例 3：
  // 输入：arr = [1], k = 1
  // 输出：1
  arr = {1};
  k = 1;
  EXPECT_EQ(solution.maxSumAfterPartitioning(arr, k), 1);
}
