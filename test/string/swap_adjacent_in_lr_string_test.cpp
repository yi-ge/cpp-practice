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
}
