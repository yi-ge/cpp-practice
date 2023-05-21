#include <array/store_water.cpp>

TEST(蓄水, storeWater) {
  Solution solution;
  // 示例 1：
  // 输入：bucket = [1,3], vat = [6,8]
  // 输出：4
  // 解释：
  // 第 1 次操作升级 bucket[0]；
  // 第 2 ~ 4 次操作均选择蓄水，即可完成蓄水要求。
  vector<int> bucket = {1, 3};
  vector<int> vat = {6, 8};
  EXPECT_EQ(solution.storeWater(bucket, vat), 4);

  // 示例 2：
  // 输入：bucket = [9,0,1], vat = [0,2,2]
  // 输出：3
  // 解释：
  // 第 1 次操作均选择升级 bucket[1]
  // 第 2~3 次操作选择蓄水，即可完成蓄水要求。
  bucket = {9, 0, 1};
  vat = {0, 2, 2};
  EXPECT_EQ(solution.storeWater(bucket, vat), 3);
}
