#include <math/maximum_students_taking_exam.cpp>

TEST(参加考试的最大学生数, maxStudents) {
  Solution solution;
  // 示例 1：
  // 输入：seats = [["#",".","#","#",".","#"],
  //               [".","#","#","#","#","."],
  //               ["#",".","#","#",".","#"]]
  // 输出：4
  // 解释：教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。
  vector<vector<char>> seats = {{'#', '.', '#', '#', '.', '#'},
                                {'.', '#', '#', '#', '#', '.'},
                                {'#', '.', '#', '#', '.', '#'}};
  EXPECT_EQ(solution.maxStudents(seats), 4);

  // 示例 2：
  // 输入：seats = [[".","#"],
  //               ["#","#"],
  //               ["#","."],
  //               ["#","#"],
  //               [".","#"]]
  // 输出：3
  // 解释：让所有学生坐在可用的座位上。
  seats = {{'.', '#'}, {'#', '#'}, {'#', '.'}, {'#', '#'}, {'.', '#'}};
  EXPECT_EQ(solution.maxStudents(seats), 3);

  // 示例 3：
  // 输入：seats = [["#",".",".",".","#"],
  //               [".","#",".","#","."],
  //               [".",".","#",".","."],
  //               [".","#",".","#","."],
  //               ["#",".",".",".","#"]]
  // 输出：10
  // 解释：让学生坐在第 1、3 和 5 列的可用座位上。
  seats = {{'#', '.', '.', '.', '#'},
           {'.', '#', '.', '#', '.'},
           {'.', '.', '#', '.', '.'},
           {'.', '#', '.', '#', '.'},
           {'#', '.', '.', '.', '#'}};
  EXPECT_EQ(solution.maxStudents(seats), 10);
}
