#include <map/letter_tile_possibilities.cpp>

TEST(活字印刷, numTilePossibilities) {
  // 示例 1：
  // 输入："AAB"
  // 输出：8
  // 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
  Solution solution;
  string tiles = "AAB";
  EXPECT_EQ(solution.numTilePossibilities(tiles), 8);

  // 示例 2：
  // 输入："AAABBC"
  // 输出：188
  tiles = "AAABBC";
  EXPECT_EQ(solution.numTilePossibilities(tiles), 188);

  // 示例 3：
  // 输入："V"
  // 输出：1
  tiles = "V";
  EXPECT_EQ(solution.numTilePossibilities(tiles), 1);
}
