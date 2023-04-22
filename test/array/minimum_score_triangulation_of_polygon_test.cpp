#include <array/minimum_score_triangulation_of_polygon.cpp>

TEST(多边形三角剖分的最低得分, minScoreTriangulation) {
  // 示例 1：
  // 输入：values = [1,2,3]
  // 输出：6
  // 解释：多边形已经三角化，唯一三角形的分数为 6。
  std::vector<int> values1{1, 2, 3};
  Solution solution;
  EXPECT_EQ(solution.minScoreTriangulation(values1), 6);

  // 示例 2：
  // 输入：values = [3,7,4,5]
  // 输出：144
  // 解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7
  // = 144。最低分数为 144。
  std::vector<int> values2{3, 7, 4, 5};
  EXPECT_EQ(solution.minScoreTriangulation(values2), 144);

  // 示例 3：
  // 输入：values = [1,3,1,4,1,5]
  // 输出：13
  // 解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。

  std::vector<int> values3{1, 3, 1, 4, 1, 5};
  EXPECT_EQ(solution.minScoreTriangulation(values3), 13);

  // 示例 4：
  // 输入：values = [4,1,3,2,5,6,8,7]
  // 输出：178
  std::vector<int> values4{4, 1, 3, 2, 5, 6, 8, 7};
  EXPECT_EQ(solution.minScoreTriangulation(values4), 178);
}
