#include <tree/maximum_sum_bst_in_binary_tree.cpp>

TEST(二叉搜索子树的最大键值和, TreeNode) {
  Solution solution;
  // 示例 1：
  // 输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
  // 输出：20
  // 解释：键值为 3 的子树是和最大的二叉搜索树。
  vector<int> treeNodes = {1,    4,    3,    2,    4,    2, 5, NULL,
                           NULL, NULL, NULL, NULL, NULL, 4, 6};
  TreeNode *root = createTree(treeNodes);
  EXPECT_EQ(solution.maxSumBST(root), 20);

  // 示例 2：
  // 输入：root = [4,3,null,1,2]
  // 输出：2
  // 解释：键值为 2 的单节点子树是和最大的二叉搜索树。
  vector<int> treeNodes2 = {4, 3, NULL, 1, 2};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_EQ(solution.maxSumBST(root2), 2);

  // 示例 3：
  // 输入：root = [-4,-2,-5]
  // 输出：0
  // 解释：所有节点键值都为负数，和最大的二叉搜索树为空。
  vector<int> treeNodes3 = {-4, -2, -5};
  TreeNode *root3 = createTree(treeNodes3);
  EXPECT_EQ(solution.maxSumBST(root3), 0);

  // 示例 4：
  // 输入：root = [2,1,3]
  // 输出：6
  vector<int> treeNodes4 = {2, 1, 3};
  TreeNode *root4 = createTree(treeNodes4);
  EXPECT_EQ(solution.maxSumBST(root4), 6);

  // 示例 5：
  // 输入：root = [5,4,8,3,null,6,3]
  // 输出：7
  vector<int> treeNodes5 = {5, 4, 8, 3, NULL, 6, 3};
  TreeNode *root5 = createTree(treeNodes5);
  EXPECT_EQ(solution.maxSumBST(root5), 7);
}
