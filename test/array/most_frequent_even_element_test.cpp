#include <array/most_frequent_even_element.cpp>

TEST(出现最频繁的偶数元素, mostFrequentEven) {
  // 示例 1：
  // 输入：nums = [0,1,2,2,4,4,1]
  // 输出：2
  // 解释：
  // 数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
  // 返回最小的那个，即返回 2 。
  Solution solution;
  vector<int> nums = {0, 1, 2, 2, 4, 4, 1};
  EXPECT_EQ(solution.mostFrequentEven(nums), 2);

  // 示例 2：
  // 输入：nums = [4,4,4,9,2,4]
  // 输出：4
  // 解释：4 是出现最频繁的偶数元素。
  nums = {4, 4, 4, 9, 2, 4};
  EXPECT_EQ(solution.mostFrequentEven(nums), 4);

  // 示例 3：
  // 输入：nums = [29,47,21,41,13,37,25,7]
  // 输出：-1
  // 解释：不存在偶数元素。
  nums = {29, 47, 21, 41, 13, 37, 25, 7};
  EXPECT_EQ(solution.mostFrequentEven(nums), -1);

  // 测试 4：
  nums = {8154, 9139, 8194, 3346, 5450, 9190,
          133,  8239, 4606, 8671, 8412, 6290};
  EXPECT_EQ(solution.mostFrequentEven(nums), 3346);
}
