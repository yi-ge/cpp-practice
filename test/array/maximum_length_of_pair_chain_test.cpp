#include <array/maximum_length_of_pair_chain.cpp>

TEST(最长数对链, findLongestChain)
{
  // 示例：
  // 输入：[[1,2], [2,3], [3,4]]
  // 输出：2
  // 解释：最长的数对链是 [1,2] -> [3,4]

  Solution solution;
  vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
  EXPECT_EQ(solution.findLongestChain(pairs), 2);
}
