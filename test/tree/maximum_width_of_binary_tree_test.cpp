#include <tree/maximum_width_of_binary_tree.cpp>

TEST(二叉树最大宽度, widthOfBinaryTree) {
  // 示例 1：
  // 输入：root = [1,3,2,5,3,null,9]
  // 输出：4
  // 解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
  Solution solution;
  vector<int> treeNodes = {1, 3, 2, 5, 3, NULL, 9};
  TreeNode *root = createTree(treeNodes);
  EXPECT_EQ(solution.widthOfBinaryTree(root), 4);

  // 示例 2：
  // 输入：root = [1,3,2,5,null,null,9,6,null,7]
  // 输出：7
  // 解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
  // vector<int> treeNodes2 = {1, 3, 2, 5, NULL, NULL, 9, 6, NULL, 7};
  // TreeNode *root2 = createTree(treeNodes2);
  // EXPECT_EQ(solution.widthOfBinaryTree(root2), 7);

  // 示例 3：
  // 输入：root = [1,3,2,5]
  // 输出：2
  // 解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
  vector<int> treeNodes3 = {1, 3, 2, 5};
  TreeNode *root3 = createTree(treeNodes3);
  EXPECT_EQ(solution.widthOfBinaryTree(root3), 2);
}
