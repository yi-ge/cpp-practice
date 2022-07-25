#include <tree/complete_binary_tree_inserter.cpp>

TEST(完全二叉树插入器, TreeNode)
{
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
}
