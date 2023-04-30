#include <math/moving_stones_until_consecutive.cpp>

TEST(移动石子直到连续, numMovesStones) {
  // 示例 1：
  // 输入：a = 1, b = 2, c = 5
  // 输出：[1, 2]
  // 解释：将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
  Solution solution;
  int a = 1;
  int b = 2;
  int c = 5;
  vector<int> res = {1, 2};
  EXPECT_EQ(solution.numMovesStones(a, b, c), res);

  // 示例 2：
  // 输入：a = 4, b = 3, c = 2
  // 输出：[0, 0]
  // 解释：我们无法进行任何移动。
  a = 4;
  b = 3;
  c = 2;
  res = {0, 0};
  EXPECT_EQ(solution.numMovesStones(a, b, c), res);

  // 示例 3：
  // 输入：a = 3, b = 5, c = 1
  // 输出：[2, 1]
  // 解释：将石子从 3 移动到 2 再移动到 4，总共需要两次移动。最多需要移动 1
  // 次来使它们连续。
  a = 3;
  b = 5;
  c = 1;
  res = {1, 2};
  EXPECT_EQ(solution.numMovesStones(a, b, c), res);
}
