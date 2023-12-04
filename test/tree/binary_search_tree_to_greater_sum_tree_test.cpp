#include "tree_node.hpp"
#include <tree/binary_search_tree_to_greater_sum_tree.cpp>

TEST(从二叉搜索树到更大和树, TreeNode) {
  Solution solution;

  // 示例 1：
  // 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
  // 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

  // Create the binary search tree
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  root->left->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(8);

  // Expected output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
  TreeNode *expected = new TreeNode(30);
  expected->left = new TreeNode(36);
  expected->right = new TreeNode(21);
  expected->left->left = new TreeNode(36);
  expected->left->right = new TreeNode(35);
  expected->right->left = new TreeNode(26);
  expected->right->right = new TreeNode(15);
  expected->left->right->right = new TreeNode(33);
  expected->right->right->right = new TreeNode(8);

  TreeNode *result = solution.bstToGst(root);

  EXPECT_EQ(treeToString(result), treeToString(expected));

  // 示例 2：
  // 输入：root = [0,null,1]
  // 输出：[1,null,1]
  TreeNode *root2 = new TreeNode(0);
  root2->right = new TreeNode(1);

  TreeNode *expected2 = new TreeNode(1);
  expected2->right = new TreeNode(1);

  TreeNode *result2 = solution.bstToGst(root2);

  EXPECT_EQ(treeToString(result2), treeToString(expected2));
}
