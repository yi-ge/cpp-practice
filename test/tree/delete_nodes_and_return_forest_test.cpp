#include "tree_node.hpp"
#include <tree/delete_nodes_and_return_forest.cpp>

TEST(删点成林, TreeNode) {
  Solution solution;
  // 示例 1：
  // 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
  // 输出：[[1,2,null,4],[6],[7]]
  vector<int> treeNodes = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root = createTree(treeNodes);
  vector<int> to_delete = {3, 5};
  vector<int> ans_vec_1 = {1, 2, NULL, 4};
  vector<int> ans_vec_2 = {6};
  vector<int> ans_vec_3 = {7};
  vector<TreeNode *> ans = {
      createTree(ans_vec_1),
      createTree(ans_vec_2),
      createTree(ans_vec_3),
  };

  // 示例 2：
  // 输入：root = [1,2,4,null,3], to_delete = [3]
  // 输出：[[1,2,4]]
  vector<int> treeNodes2 = {1, 2, 4, NULL, 3};
  TreeNode *root2 = createTree(treeNodes2);
  vector<int> to_delete2 = {3};
  vector<int> ans2_vec = {1, 2, 4};
  vector<TreeNode *> ans2 = {createTree(ans2_vec)};
  vector<TreeNode *> res2 = solution.delNodes(root2, to_delete2);
  for (int i = 0; i < res2.size(); ++i) {
    EXPECT_EQ(treeToString(res2[i]), treeToString(ans2[i]));
  }
}
