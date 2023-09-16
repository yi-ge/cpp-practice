#include <array/house_robber.cpp>

TEST(打家劫舍, rob) {
  Solution solution;
  // 示例 1：
  // 输入：[1,2,3,1]
  // 输出：4
  // 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
  //      偷窃到的最高金额 = 1 + 3 = 4 。
  std::vector<int> nums1 = {1, 2, 3, 1};
  EXPECT_EQ(solution.rob(nums1), 4);

  // 示例 2：
  // 输入：[2,7,9,3,1]
  // 输出：12
  // 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋
  // (金额 = 1)。      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
  std::vector<int> nums2 = {2, 7, 9, 3, 1};
  EXPECT_EQ(solution.rob(nums2), 12);
}
