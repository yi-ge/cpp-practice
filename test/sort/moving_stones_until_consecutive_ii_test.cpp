#include <sort/moving_stones_until_consecutive_ii.cpp>

TEST(移动石子直到连续2, numMovesStonesII) {
  // 示例 1：
  // 输入：[7,4,9]
  // 输出：[1,2]
  // 解释：
  // 我们可以移动一次，4 -> 8，游戏结束。
  // 或者，我们可以移动两次 9 -> 5，4 -> 6，游戏结束。
  Solution solution;
  vector<int> stones1 = {7, 4, 9};
  vector<int> expected1 = {1, 2};
  vector<int> result1 = solution.numMovesStonesII(stones1);
  EXPECT_EQ(expected1, result1);

  // 示例 2：
  // 输入：[6,5,4,3,10]
  // 输出：[2,3]
  // 解释：
  // 我们可以移动 3 -> 8，接着是 10 -> 7，游戏结束。
  // 或者，我们可以移动 3 -> 7, 4 -> 8, 5 -> 9，游戏结束。
  // 注意，我们无法进行 10 -> 2 这样的移动来结束游戏，因为这是不合要求的移动。
  vector<int> stones2 = {6, 5, 4, 3, 10};
  vector<int> expected2 = {2, 3};
  vector<int> result2 = solution.numMovesStonesII(stones2);
  EXPECT_EQ(expected2, result2);

  // 示例 3：
  // 输入：[100,101,104,102,103]
  // 输出：[0,0]
  vector<int> stones3 = {100, 101, 104, 102, 103};
  vector<int> expected3 = {0, 0};
  vector<int> result3 = solution.numMovesStonesII(stones3);
  EXPECT_EQ(expected3, result3);
}
