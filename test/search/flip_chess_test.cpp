#include <search/flip_chess.cpp>

TEST(黑白翻转棋, flipChess) {
  Solution solution;
  // 示例 1：
  // 输入：chessboard = ["....X.","....X.","XOOO..","......","......"]
  // 输出：3
  // 解释： 可以选择下在 [2,4] 处，能够翻转白方三枚棋子。
  vector<string> chessboard = {"....X.", "....X.", "XOOO..", "......",
                               "......"};
  EXPECT_EQ(solution.flipChess(chessboard), 3);

  // 示例 2：
  // 输入：chessboard = [".X.",".O.","XO."]
  // 输出：2
  // 解释： 可以选择下在 [2,2] 处，能够翻转白方两枚棋子。
  chessboard = {".X.", ".O.", "XO."};
  EXPECT_EQ(solution.flipChess(chessboard), 2);

  // 示例 3：
  // 输入：chessboard =
  // [".......",".......",".......","X......",".O.....","..O....","....OOX"]
  // 输出：4
  // 解释： 可以选择下在 [6,3] 处，能够翻转白方四枚棋子。
  chessboard = {".......", ".......", ".......", "X......",
                ".O.....", "..O....", "....OOX"};
  EXPECT_EQ(solution.flipChess(chessboard), 4);
}
