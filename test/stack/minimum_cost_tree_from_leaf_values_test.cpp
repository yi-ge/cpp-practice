#include <stack/minimum_cost_tree_from_leaf_values.cpp>

TEST(叶值的最小代价生成树, mctFromLeafValues) {
  Solution solution;
  // 示例 1：
  // 输入：arr = [6,2,4]
  // 输出：32
  // 解释：有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为
  // 32 。
  vector<int> arr = {6, 2, 4};
  EXPECT_EQ(solution.mctFromLeafValues(arr), 32);

  // 示例 2：
  // 输入：arr = [4,11]
  // 输出：44
  vector<int> arr2 = {4, 11};
  EXPECT_EQ(solution.mctFromLeafValues(arr2), 44);
}
