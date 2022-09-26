#include <math/rotated_digits.cpp>

TEST(旋转数字, rotatedDigits) {
  // 示例：
  // 输入: 10
  // 输出: 4
  // 解释:
  // 在[1, 10]中有四个好数： 2, 5, 6, 9。
  // 注意 1 和 10 不是好数, 因为他们在旋转之后不变。

  Solution solution;
  EXPECT_EQ(solution.rotatedDigits(10), 4);
}
