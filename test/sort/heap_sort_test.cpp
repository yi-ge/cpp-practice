#include <sort/heap_sort.cpp>

TEST(堆排序, heapSort) {
  Solution solution;
  vector<int> nums = {2, 1, 3, 5, 4};
  vector<int> actionVec = {1, 2, 3, 4, 5};
  EXPECT_THAT(solution.heapSort(nums), ::testing::ContainerEq(actionVec));
}