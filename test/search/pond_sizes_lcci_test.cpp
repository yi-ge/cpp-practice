#include <search/pond_sizes_lcci.cpp>

TEST(水域大小, pondSizes) {
  // 示例：
  // 输入：
  // [
  //   [0,2,1,0],
  //   [0,1,0,1],
  //   [1,1,0,1],
  //   [0,1,0,1]
  // ]
  // 输出： [1,2,4]

  Solution solution;
  vector<vector<int>> land = {
      {0, 2, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {0, 1, 0, 1}};
  vector<int> result = {1, 2, 4};
  EXPECT_EQ(solution.pondSizes(land), result);
}
