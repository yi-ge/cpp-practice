#include <array/reverse_subarray_to_maximize_array_value.cpp>

TEST(翻转子数组得到最大的数组值, maxValueAfterReverse) {
  // 示例 1：
  // 输入：nums = [2,3,1,5,4]
  // 输出：10
  // 解释：通过翻转子数组 [3,1,5] ，数组变成 [2,5,1,3,4] ，数组值为 10 。
  // base=∣2−3∣+∣3−1∣+∣1−5∣+∣5−4∣=1+2+4+1=8。
  // 翻转后
  // base=∣2−5∣+∣5−1∣+∣1−3∣+∣3−4∣=3+4+2+1=10。
  Solution solution;
  vector<int> nums = {2, 3, 1, 5, 4};
  EXPECT_EQ(solution.maxValueAfterReverse(nums), 10);

  // 示例 2：
  // 输入：nums = [2,4,9,24,2,1,10]
  // 输出：68
  nums = {2, 4, 9, 24, 2, 1, 10};
  EXPECT_EQ(solution.maxValueAfterReverse(nums), 68);
}
