#include <array/rank_transform_of_an_array.cpp>

TEST(数组序号转换, arrayRankTransform)
{
  // 示例 1：
  // 输入：arr = [40,10,20,30]
  // 输出：[4,1,2,3]
  // 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
  Solution solution;
  vector<int> arr = {40, 10, 20, 30};
  vector<int> arr1 = {4, 1, 2, 3};
  EXPECT_THAT(solution.arrayRankTransform(arr), ::testing::ContainerEq(arr1));

  // 示例 2：
  // 输入：arr = [100,100,100]
  // 输出：[1,1,1]
  // 解释：所有元素有相同的序号。
  vector<int> arr2 = {100, 100, 100};
  vector<int> arr3 = {1, 1, 1};
  EXPECT_THAT(solution.arrayRankTransform(arr2), ::testing::ContainerEq(arr3));

  // 示例 3：
  // 输入：arr = [37,12,28,9,100,56,80,5,12]
  // 输出：[5,3,4,2,8,6,7,1,3]
  vector<int> arr4 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
  vector<int> arr5 = {5, 3, 4, 2, 8, 6, 7, 1, 3};
  EXPECT_THAT(solution.arrayRankTransform(arr4), ::testing::ContainerEq(arr5));
}
