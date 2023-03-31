#include <array/number_of_arithmetic_triplets.cpp>

TEST(算术三元组的数目, arithmeticTriplets) {
  // 示例 1：
  // 输入：nums = [0,1,4,6,7,10], diff = 3
  // 输出：2
  // 解释：
  // (1, 2, 4) 是算术三元组：7 - 4 == 3 且 4 - 1 == 3 。
  // (2, 4, 5) 是算术三元组：10 - 7 == 3 且 7 - 4 == 3 。
  Solution solution1;
  std::vector<int> nums1 = {0, 1, 4, 6, 7, 10};
  int diff1 = 3;
  EXPECT_EQ(solution1.arithmeticTriplets(nums1, diff1), 2);

  // 示例 2：
  // 输入：nums = [4,5,6,7,8,9], diff = 2
  // 输出：2
  // 解释：
  // (0, 2, 4) 是算术三元组：8 - 6 == 2 且 6 - 4 == 2 。
  // (1, 3, 5) 是算术三元组：9 - 7 == 2 且 7 - 5 == 2 。
  Solution solution2;
  std::vector<int> nums2 = {4, 5, 6, 7, 8, 9};
  int diff2 = 2;
  EXPECT_EQ(solution2.arithmeticTriplets(nums2, diff2), 2);

  // 示例 3：
  // 输入：nums = [1, 2, 3], diff = 1
  // 输出：1
  // 解释：
  // (0, 1, 2) 是算术三元组：3 - 2 == 1 且 2 - 1 == 1 。
  Solution solution3;
  std::vector<int> nums3 = {1, 2, 3};
  int diff3 = 1;
  EXPECT_EQ(solution3.arithmeticTriplets(nums3, diff3), 1);
}
