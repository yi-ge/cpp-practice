#include <sort/merge_sort.cpp>

TEST(归并排序, mergeSort)
{
  Solution solution;
  vector<int> nums = {2, 1, 3, 5, 4};
  vector<int> actionVec = {1, 2, 3, 4, 5};
  EXPECT_THAT(solution.mergeSort(nums), ::testing::ContainerEq(actionVec));
}