#include "tree_node.hpp"
#include <gtest/gtest.h>
#include <tree/path_sum.cpp>

TEST(路径总和, hasPathSum) {
  // 示例 1：
  // 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
  // 输出：true
  // 解释：等于目标和的根节点到叶节点路径如上图所示。
  Solution solution;
  vector<int> treeNodes = {5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, 1};
  TreeNode *root = createTree(treeNodes);
  EXPECT_TRUE(solution.hasPathSum(root, 22));

  // 示例 2：
  // 输入：root = [1,2,3], targetSum = 5
  // 输出：false
  // 解释：树中存在两条根节点到叶子节点的路径：
  // (1 --> 2): 和为 3
  // (1 --> 3): 和为 4
  // 不存在 sum = 5 的根节点到叶子节点的路径。
  // 示例 3：
  // 输入：root = [], targetSum = 0
  // 输出：false
  // 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
  vector<int> treeNodes2 = {1, 2, 3};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_FALSE(solution.hasPathSum(root2, 5));

  TreeNode *root3 = nullptr;
  EXPECT_FALSE(solution.hasPathSum(root3, 1));
}
