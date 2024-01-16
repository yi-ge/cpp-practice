#include <math/count_of_integers.cpp>

TEST(统计整数数目, count) {
  Solution solution;
  // 示例 1：
  // 输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
  // 输出：11
  // 解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11
  // 和 12 。所以我们返回 11 。
  string num1 = "1";
  string num2 = "12";
  int min_sum = 1;
  int max_sum = 8;
  EXPECT_EQ(solution.count(num1, num2, min_sum, max_sum), 11);

  // 示例 2：
  // 输入：num1 = "1", num2 = "5", min_num = 1, max_num = 5
  // 输出：5
  // 解释：数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5
  // 。
  num1 = "1";
  num2 = "5";
  min_sum = 1;
  max_sum = 5;
  EXPECT_EQ(solution.count(num1, num2, min_sum, max_sum), 5);
}
