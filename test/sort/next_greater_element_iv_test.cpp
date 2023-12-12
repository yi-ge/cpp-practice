#include <sort/next_greater_element_iv.cpp>

TEST(下一个更大元素IV, secondGreaterElement) {
  Solution solution;
  // 示例 1：
  // 输入：nums = [2,4,0,9,6]
  // 输出：[9,6,6,-1,-1]
  // 解释：
  // 下标为 0 处：2 的右边，4 是大于 2 的第一个整数，9 是第二个大于 2 的整数。
  // 下标为 1 处：4 的右边，9 是大于 4 的第一个整数，6 是第二个大于 4 的整数。
  // 下标为 2 处：0 的右边，9 是大于 0 的第一个整数，6 是第二个大于 0 的整数。
  // 下标为 3 处：右边不存在大于 9 的整数，所以第二大整数为 -1 。
  // 下标为 4 处：右边不存在大于 6 的整数，所以第二大整数为 -1 。
  // 所以我们返回 [9,6,6,-1,-1] 。
  vector<int> nums = {2, 4, 0, 9, 6};
  EXPECT_EQ(solution.secondGreaterElement(nums),
            vector<int>({9, 6, 6, -1, -1}));

  // 示例 2：
  // 输入：nums = [3,3]
  // 输出：[-1,-1]
  // 解释：
  // 由于每个数右边都没有更大的数，所以我们返回 [-1,-1] 。
  nums = {3, 3};
  EXPECT_EQ(solution.secondGreaterElement(nums), vector<int>({-1, -1}));
}
