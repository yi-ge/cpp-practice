#include "tree_node.hpp"
#include <tree/lowest_common_ancestor_of_a_binary_search_tree.cpp>

TEST(二叉搜索树的最近公共祖先, lowestCommonAncestor) {
  // 示例 1:
  // 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
  // 输出: 6
  // 解释: 节点 2 和节点 8 的最近公共祖先是 6。
  Solution solution;
  vector<int> treeNodes = {6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5};
  TreeNode *root = createTree(treeNodes);
  TreeNode *p = root->left;
  TreeNode *q = root->right;
  EXPECT_EQ(treeToString(solution.lowestCommonAncestor(root, p, q)),
            treeToString(root));

  // 示例 2:
  // 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
  // 输出: 2
  // 解释: 节点 2 和节点 4 的最近公共祖先是 2,
  // 因为根据定义最近公共祖先节点可以为节点本身。
  TreeNode *p2 = root->left;
  TreeNode *q2 = root->left->right;
  EXPECT_EQ(treeToString(solution.lowestCommonAncestor(root, p2, q2)),
            treeToString(p2));
}
