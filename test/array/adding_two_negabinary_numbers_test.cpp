#include <array/adding_two_negabinary_numbers.cpp>

TEST(负二进制数相加, addNegabinary) {
  // 示例 1：
  // 输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
  // 输出：[1,0,0,0,0]
  // 解释：arr1 表示 11，arr2 表示 5，输出表示 16 。
  Solution solution;
  vector<int> arr1 = {1, 1, 1, 1, 1};
  vector<int> arr2 = {1, 0, 1};
  vector<int> result = {1, 0, 0, 0, 0};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), result);

  // 示例 2：
  // 输入：arr1 = [0], arr2 = [0]
  // 输出：[0]
  arr1 = {0};
  arr2 = {0};
  result = {0};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), result);

  // 示例 3：
  // 输入：arr1 = [0], arr2 = [1]
  // 输出：[1]
  arr1 = {0};
  arr2 = {1};
  result = {1};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), result);
}
