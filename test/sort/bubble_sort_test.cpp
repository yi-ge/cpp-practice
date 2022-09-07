#include <sort/bubble_sort.cpp>

TEST(冒泡排序, bubbleSort) {
  Solution solution;
  vector<int> nums = {2, 1, 3, 5, 4};
  vector<int> actionVec = {1, 2, 3, 4, 5};
  EXPECT_THAT(solution.bubbleSort(nums), ::testing::ContainerEq(actionVec));
}