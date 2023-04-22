#include <tree/maximum_difference_between_node_and_ancestor.cpp>

TEST(节点与其祖先之间的最大差值, TreeNode) {
  // 示例 1：
  // 输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
  // 输出：7
  // 解释：
  // 我们有大量的节点与其祖先的差值，其中一些如下：
  // |8 - 3| = 5
  // |3 - 7| = 4
  // |8 - 1| = 7
  // |10 - 13| = 3
  // 在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
  Solution solution;
  vector<int> treeNodes = {8, 3, 10, 1, 6, NULL, 14, NULL, NULL, 4, 7, 13};
  TreeNode *root = createTree(treeNodes);
  EXPECT_EQ(solution.maxAncestorDiff(root), 7);

  // 示例 2：
  // 输入：root = [1,null,2,null,0,3]
  // 输出：3
  Solution solution2;
  TreeNode *root2 = new TreeNode(1);
  root2->right = new TreeNode(2);
  root2->right->right = new TreeNode(0);
  root2->right->right->left = new TreeNode(3);
  EXPECT_EQ(solution2.maxAncestorDiff(root2), 3);
}
