#include "tree_node.hpp"
#include <gtest/gtest.h>
#include <tree/validate_binary_search_tree.cpp>

TEST(验证二叉搜索树, isValidBST) {
  // 示例 1：
  // 输入：root = [2,1,3]
  // 输出：true
  Solution solution;
  vector<int> treeNodes = {2, 1, 3};
  TreeNode *root = createTree(treeNodes);
  EXPECT_TRUE(solution.isValidBST(root));

  // 示例 2：
  // 输入：root = [5,1,4,null,null,3,6]
  // 输出：false
  // 解释：根节点的值是 5 ，但是右子节点的值是 4 。
  vector<int> treeNodes2 = {5, 1, 4, NULL, NULL, 3, 6};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_FALSE(solution.isValidBST(root2));
}
