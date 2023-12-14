#include <array/stamping_the_grid.cpp>

TEST(用邮票贴满网格图, possibleToStamp) {
  Solution solution;
  // 示例 1：
  // 输入：grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]],
  // stampHeight = 4, stampWidth = 3 输出：true
  // 解释：我们放入两个有重叠部分的邮票（图中标号为 1 和
  // 2），它们能覆盖所有与空格子。
  vector<vector<int>> grid = {
      {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  int stampHeight = 4, stampWidth = 3;
  EXPECT_TRUE(solution.possibleToStamp(grid, stampHeight, stampWidth));

  // 示例 2：
  // 输入：grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2,
  // stampWidth = 2 输出：false
  // 解释：没办法放入邮票覆盖所有的空格子，且邮票不超出网格图以外。
  grid = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  stampHeight = 2, stampWidth = 2;
  EXPECT_FALSE(solution.possibleToStamp(grid, stampHeight, stampWidth));
}
