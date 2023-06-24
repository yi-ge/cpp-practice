#include <math/maximize_grid_happiness.cpp>

TEST(最大化网格幸福感, getMaxGridHappiness) {
  Solution solution;
  // 示例 1：
  // 输入：m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
  // 输出：240
  // 解释：假设网格坐标 (row, column) 从 1 开始编号。
  // 将内向的人放置在单元 (1,1) ，将外向的人放置在单元 (1,3) 和 (2,3) 。
  // - 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (0 * 30)（0 位邻居）=
  // 120
  // - 位于 (1,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
  // - 位于 (2,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
  // 网格幸福感为：120 + 60 + 60 = 240
  // 上图展示该示例对应网格中每个人的幸福感。内向的人在浅绿色单元中，而外向的人在浅紫色单元中。
  int m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2;
  EXPECT_EQ(
      solution.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
      240);

  // 示例 2：
  // 输入：m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1
  // 输出：260
  // 解释：将内向的人放置在单元 (1,1) 和 (3,1) ，将外向的人放置在单元 (2,1) 。
  // - 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）=
  // 90
  // - 位于 (2,1) 的外向的人的幸福感：40（初始幸福感）+ (2 * 20)（2 位邻居）= 80
  // - 位于 (3,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）=
  // 90 网格幸福感为 90 + 80 + 90 = 260
  m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1;
  EXPECT_EQ(
      solution.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
      260);

  // 示例 3：
  // 输入：m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0
  // 输出：240
  m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0;
  EXPECT_EQ(
      solution.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
      240);
}
