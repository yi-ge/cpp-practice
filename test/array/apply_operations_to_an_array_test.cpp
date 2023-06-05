#include <array/apply_operations_to_an_array.cpp>

TEST(对数组执行操作, applyOperations) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [1,2,2,1,1,0]
  // 输出：[1,4,2,0,0,0]
  // 解释：执行以下操作：
  // - i = 0: nums[0] 和 nums[1] 不相等，跳过这步操作。
  // - i = 1: nums[1] 和 nums[2] 相等，nums[1] 的值变成原来的 2 倍，nums[2]
  // 的值变成 0 。数组变成 [1,4,0,1,1,0] 。
  // - i = 2: nums[2] 和 nums[3] 不相等，所以跳过这步操作。
  // - i = 3: nums[3] 和 nums[4] 相等，nums[3] 的值变成原来的 2 倍，nums[4]
  // 的值变成 0 。数组变成 [1,4,0,2,0,0] 。
  // - i = 4: nums[4] 和 nums[5] 相等，nums[4] 的值变成原来的 2 倍，nums[5]
  // 的值变成 0 。数组变成 [1,4,0,2,0,0] 。 执行完所有操作后，将 0
  // 全部移动到数组末尾，得到结果数组 [1,4,2,0,0,0] 。
  vector<int> nums = {1, 2, 2, 1, 1, 0};
  vector<int> res = {1, 4, 2, 0, 0, 0};
  EXPECT_EQ(solution.applyOperations(nums), res);

  // 示例 2：
  // 输入：nums = [0,1]
  // 输出：[1,0]
  // 解释：无法执行任何操作，只需要将 0 移动到末尾。
  nums = {0, 1};
  res = {1, 0};
  EXPECT_EQ(solution.applyOperations(nums), res);
}
