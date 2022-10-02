#include <gtest/gtest.h>
#include <string/swap_adjacent_in_lr_string.cpp>

TEST(在LR字符串中交换相邻字符, canTransform) {
  // 示例 :
  // 输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
  // 输出: True
  // 解释:
  // 我们可以通过以下几步将start转换成end:
  // RXXLRXRXL ->
  // XRXLRXRXL ->
  // XRLXRXRXL ->
  // XRLXXRRXL ->
  // XRLXXRRLX
  Solution solution;
  string start = "RXXLRXRXL";
  string end = "XRLXXRRLX";
  EXPECT_EQ(solution.canTransform(start, end), 1);

  string start2 = "X";
  string end2 = "L";
  EXPECT_EQ(solution.canTransform(start2, end2), false);

  string start3 = "XXL";
  string end3 = "XXR";
  EXPECT_FALSE(solution.canTransform(start3, end3));

  string start4 = "R";
  string end4 = "X";
  EXPECT_FALSE(solution.canTransform(start4, end4));

  string start5 = "XLX";
  string end5 = "XXL";
  EXPECT_FALSE(solution.canTransform(start5, end5));

  string start6 = "XXR";
  string end6 = "XRX";
  EXPECT_FALSE(solution.canTransform(start6, end6));

  string start7 = "RXR";
  string end7 = "XXR";
  EXPECT_FALSE(solution.canTransform(start7, end7));
}
