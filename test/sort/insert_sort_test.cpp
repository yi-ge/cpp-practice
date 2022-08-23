#include <sort/insert_sort.cpp>

TEST(插入排序, insertSort)
{
  Solution solution;
  vector<int> nums = {2, 1, 3, 5, 4};
  vector<int> actionVec = {1, 2, 3, 4, 5};
  EXPECT_THAT(solution.insertSort(nums), ::testing::ContainerEq(actionVec));
}