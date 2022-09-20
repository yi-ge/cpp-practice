#include <math/add_strings.cpp>

TEST(字符串相加, addStrings) {
  // 示例 1：
  // 输入：num1 = "11", num2 = "123"
  // 输出："134"
  Solution solution;
  string num1 = "11";
  string num2 = "123";
  EXPECT_EQ(solution.addStrings(num1, num2), "134");

  // 示例 2：
  // 输入：num1 = "456", num2 = "77"
  // 输出："533"
  string num21 = "456";
  string num22 = "77";
  EXPECT_EQ(solution.addStrings(num21, num22), "533");

  // 示例 3：
  // 输入：num1 = "0", num2 = "0"
  // 输出："0"
  string num31 = "0";
  string num32 = "0";
  EXPECT_EQ(solution.addStrings(num31, num32), "0");
}
