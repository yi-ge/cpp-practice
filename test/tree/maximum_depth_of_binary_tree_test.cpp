#include "tree_node.hpp"
#include <tree/maximum_depth_of_binary_tree.cpp>

TEST(二叉树的最大深度, TreeNode) {
  // 示例：
  // 给定二叉树 [3,9,20,null,null,15,7]
  //     3
  //    / \
  //   9  20
  //     /  \
  //    15   7
  // 返回它的最大深度 3 。
  Solution solution;
  vector<int> treeNodes = {3, 9, 20, NULL, NULL, 15, 7};
  TreeNode *root = createTree(treeNodes);
  EXPECT_EQ(solution.maxDepth(root), 3);
  vector<int> nullNode = {};
  TreeNode *node = createTree(nullNode);
  EXPECT_EQ(solution.maxDepth(node), 0);
}
