#include "tree_node.hpp"
#include <tree/two_sum_iv_input_is_a_bst.cpp>

TEST(两数之和_IV, TreeNode) {
  // 示例 1：
  // 输入: root = [5,3,6,2,4,null,7], k = 9
  // 输出: true
  Solution solution;
  vector<int> treeNodes = {5, 3, 6, 2, 4, NULL, 7};
  TreeNode *root = createTree(treeNodes);
  EXPECT_TRUE(solution.findTarget(root, 9));

  // 示例 2：
  // 输入: root = [5,3,6,2,4,null,7], k = 28
  // 输出: false
  vector<int> treeNodes2 = {5, 3, 6, 2, 4, NULL, 7};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_FALSE(solution.findTarget(root2, 28));
}
