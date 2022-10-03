#include "tree_node.hpp"
#include <gtest/gtest.h>
#include <tree/two_sum_iv_input_is_a_bst.cpp>

TEST(两数之和_IV, findTarget) {
  // 示例 1：
  // 输入: root = [5,3,6,2,4,null,7], k = 9
  // 输出: true
  Solution *sol = new Solution();
  vector<int> treeNodes = {5, 3, 6, 2, 4, NULL, 7};
  TreeNode *root = createTree(treeNodes);
  EXPECT_TRUE(sol->findTarget(root, 9));
  delete sol;

  // 示例 2：
  // 输入: root = [5,3,6,2,4,null,7], k = 28
  // 输出: false
  Solution *solution2 = new Solution();
  EXPECT_FALSE(solution2->findTarget(root, 28));
  delete solution2;
}
