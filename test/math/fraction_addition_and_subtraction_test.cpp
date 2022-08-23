#include <math/fraction_addition_and_subtraction.cpp>

TEST(分数加减运算, fractionAddition)
{
  // 示例 1:
  // 输入: expression = "-1/2+1/2"
  // 输出: "0/1"
  Solution solution;
  EXPECT_STREQ(solution.fractionAddition("-1/2+1/2").c_str(), "0/1");

  //  示例 2:
  // 输入: expression = "-1/2+1/2+1/3"
  // 输出: "1/3"
  EXPECT_STREQ(solution.fractionAddition("-1/2+1/2+1/3").c_str(), "1/3");

  // 示例 3:
  // 输入: expression = "1/3-1/2"
  // 输出: "-1/6"
  EXPECT_STREQ(solution.fractionAddition("1/3-1/2").c_str(), "-1/6");
}
