#include <sort/make_array_strictly_increasing.cpp>

TEST(使数组严格递增, makeArrayIncreasing) {
  // 示例 1：
  // 输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
  // 输出：1
  // 解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。
  Solution solution;
  vector<int> arr1 = {1, 5, 3, 6, 7};
  vector<int> arr2 = {1, 3, 2, 4};
  EXPECT_EQ(solution.makeArrayIncreasing(arr1, arr2), 1);

  // 示例 2：
  // 输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]
  // 输出：2
  // 解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。
  arr1 = {1, 5, 3, 6, 7};
  arr2 = {4, 3, 1};
  EXPECT_EQ(solution.makeArrayIncreasing(arr1, arr2), 2);

  // 示例 3：
  // 输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
  // 输出：-1
  // 解释：无法使 arr1 严格递增。
  arr1 = {1, 5, 3, 6, 7};
  arr2 = {1, 6, 3, 3};
  EXPECT_EQ(solution.makeArrayIncreasing(arr1, arr2), -1);
}
