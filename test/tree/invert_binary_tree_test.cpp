#include "tree_node.hpp"
#include <gtest/gtest.h>
#include <tree/invert_binary_tree.cpp>

TEST(翻转二叉树, invertTree) {
  // 示例 1：
  Solution solution;
  vector<int> treeNodes = {4, 2, 7, 1, 3, 6, 9};
  TreeNode *root = createTree(treeNodes);
  vector<int> treeNodesRes = {4, 7, 2, 9, 6, 3, 1};
  TreeNode *resRoot = createTree(treeNodesRes);
  EXPECT_STREQ(treeToString(solution.invertTree(root)).c_str(),
               treeToString(resRoot).c_str());

  // 示例 2：
  vector<int> treeNodes2 = {2, 1, 3};
  TreeNode *root2 = createTree(treeNodes2);
  vector<int> treeNodesRes2 = {2, 3, 1};
  TreeNode *resRoot2 = createTree(treeNodesRes2);
  EXPECT_EQ(treeToString(solution.invertTree(root2)), treeToString(resRoot2));

  // 示例 3：
  // 输入：root = []
  // 输出：[]
  TreeNode *root3 = new TreeNode();
  TreeNode *resRoot3 = new TreeNode();
  EXPECT_STREQ(treeToString(solution.invertTree(root3)).c_str(),
               treeToString(resRoot3).c_str());
}
