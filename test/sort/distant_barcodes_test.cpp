#include <sort/distant_barcodes.cpp>

TEST(距离相等的条形码, rearrangeBarcodes) {
  // 示例 1：
  // 输入：barcodes = [1,1,1,2,2,2]
  // 输出：[2,1,2,1,2,1]
  Solution solution;
  vector<int> barcodes = {1, 1, 1, 2, 2, 2};
  vector<int> res = {2, 1, 2, 1, 2, 1};
  EXPECT_EQ(solution.rearrangeBarcodes(barcodes), res);

  // 示例 2：
  // 输入：barcodes = [1,1,1,1,2,2,3,3]
  // 输出：[1,3,1,3,2,1,2,1]
  barcodes = {1, 1, 1, 1, 2, 2, 3, 3};
  res = {1, 3, 1, 2, 1, 3, 2, 1}; // 可能存在多个正确的答案
  EXPECT_EQ(solution.rearrangeBarcodes(barcodes), res);
}
