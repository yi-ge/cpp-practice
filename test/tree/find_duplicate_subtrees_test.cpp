#include "tree_node.hpp"
#include <tree/find_duplicate_subtrees.cpp>

TEST(寻找重复的子树, findDuplicateSubtrees) {
  // 示例 1：
  // 输入：root = [1,2,3,4,null,2,4,null,null,4]
  // 输出：[[2,4],[4]]
  Solution solution;
  vector<int> treeNodes = {1, 2, 3, 4, NULL, 2, 4, NULL, NULL, 4};
  TreeNode *root = createTree(treeNodes);
  vector<int> ans_vec_1 = {2, 4};
  vector<int> ans_vec_2 = {4};
  vector<TreeNode *> ans = {
      createTree(ans_vec_2),
      createTree(ans_vec_1),
  };

  printTree(root);

  vector<TreeNode *> res = solution.findDuplicateSubtrees(root);
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(treeToString(res[i]), treeToString(ans[i]));
  }

  // 示例 2：
  // 输入：root = [2,1,1]
  // 输出：[[1]]
  Solution solution2;
  vector<int> treeNodes2 = {2, 1, 1};
  TreeNode *root2 = createTree(treeNodes2);
  vector<int> ans2_vec = {1};
  vector<TreeNode *> ans2 = {createTree(ans2_vec)};
  vector<TreeNode *> res2 = solution2.findDuplicateSubtrees(root2);
  for (int i = 0; i < res2.size(); ++i) {
    EXPECT_EQ(treeToString(res2[i]), treeToString(ans2[i]));
  }

  // 示例 3：
  // 输入：root = [2,2,2,3,null,3,null]
  // 输出：[[2,3],[3]]
  Solution solution3;
  vector<int> treeNodes3 = {2, 2, 2, 3, NULL, 3, NULL};
  TreeNode *root3 = createTree(treeNodes3);
  vector<int> ans3_vec_1 = {2, 3};
  vector<int> ans3_vec_2 = {3};
  vector<TreeNode *> ans3 = {
      createTree(ans3_vec_2),
      createTree(ans3_vec_1),
  };
  vector<TreeNode *> res3 = solution3.findDuplicateSubtrees(root3);
  for (int i = 0; i < res3.size(); ++i) {
    EXPECT_EQ(treeToString(res3[i]), treeToString(ans3[i]));
  }
}
