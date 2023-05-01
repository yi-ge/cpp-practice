#include <map/powerful_integers.cpp>

TEST(强整数, powerfulIntegers) {
  // 示例 1：
  // 输入：x = 2, y = 3, bound = 10
  // 输出：[2,3,4,5,7,9,10]
  // 解释：
  // 2 = 20 + 30
  // 3 = 21 + 30
  // 4 = 20 + 31
  // 5 = 21 + 31
  // 7 = 22 + 31
  // 9 = 23 + 30
  // 10 = 20 + 32
  Solution solution;
  int x = 2;
  int y = 3;
  int bound = 10;
  vector<int> result = {10, 2, 4, 3, 5, 7, 9};
  EXPECT_EQ(solution.powerfulIntegers(x, y, bound), result);

  // 示例 2：
  // 输入：x = 3, y = 5, bound = 15
  // 输出：[2,4,6,8,10,14]
  x = 3;
  y = 5;
  bound = 15;
  result = {10, 2, 14, 6, 4, 8};
  EXPECT_EQ(solution.powerfulIntegers(x, y, bound), result);
}
