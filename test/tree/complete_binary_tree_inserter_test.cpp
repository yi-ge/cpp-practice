#include <tree/complete_binary_tree_inserter.cpp>

TEST(完全二叉树插入器, CBTInserter) {
  TreeNode *left = new TreeNode(2);
  TreeNode *root = new TreeNode(1, left, nullptr);
  CBTInserter *obj = new CBTInserter(root);
  int param_1 = obj->insert(3);
  EXPECT_EQ(param_1, 1);
  int param_2 = obj->insert(4);
  EXPECT_EQ(param_2, 2);
  TreeNode *back_root = obj->get_root();
  EXPECT_EQ(back_root->val, 1);
  EXPECT_EQ(back_root->left->val, 2);
  EXPECT_EQ(back_root->right->val, 3);
  EXPECT_EQ(back_root->left->left->val, 4);

  TreeNode *left2 = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root2 = new TreeNode(1, left2, right);
  CBTInserter *obj2 = new CBTInserter(root2);

  TreeNode *back_root2 = obj2->get_root();
  EXPECT_EQ(back_root2->val, 1);
}
