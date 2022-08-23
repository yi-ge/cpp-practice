#include <sort/quick_sort.cpp>

TEST(快速排序, quickSort)
{
  Solution solution;
  vector<int> nums = {2, 1, 3, 7, 5, 4, 8};
  vector<int> actionVec = {1, 2, 3, 4, 5, 7, 8};
  solution.quickSort(nums);
  EXPECT_THAT(nums, ::testing::ContainerEq(actionVec));
}