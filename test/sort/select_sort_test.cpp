#include <sort/select_sort.cpp>

TEST(选择排序, selectSort)
{
  Solution solution;
  vector<int> nums = {2, 1, 3, 5, 4};
  vector<int> actionVec = {1, 2, 3, 4, 5};
  EXPECT_THAT(solution.selectSort(nums), ::testing::ContainerEq(actionVec));
}