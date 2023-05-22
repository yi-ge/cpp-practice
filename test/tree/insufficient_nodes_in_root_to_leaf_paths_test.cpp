#include <tree/insufficient_nodes_in_root_to_leaf_paths.cpp>

TEST(根到叶路径上的不足节点, TreeNode) {
  Solution solution;
  // 示例 1：
  // 输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
  // 输出：[1,2,3,4,null,null,7,8,9,null,14]
  vector<int> treeNodes = {1, 2,   3,   4,  -99, -99, 7, 8,
                           9, -99, -99, 12, 13,  -99, 14};
  TreeNode *root = createTree(treeNodes);
  printTree(root);
  TreeNode *result = solution.sufficientSubset(root, 1);
  vector<int> resultNodes = {1, 2,    3,    4,    NULL, NULL, 7, 8,
                             9, NULL, NULL, NULL, NULL, NULL, 14};
  TreeNode *expect = createTree(resultNodes);
  printTree(result);
  printTree(expect);
  EXPECT_STREQ(treeToString(result).c_str(), treeToString(expect).c_str());

  // 示例 2：
  // 输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
  // 输出：[5,4,8,11,null,17,4,7,null,null,null,5]
  treeNodes = {5, 4, 8, 11, NULL, 17, 4, 7, 1, NULL, NULL, 5, 3};
  root = createTree(treeNodes);
  result = solution.sufficientSubset(root, 22);
  resultNodes = {5, 4, 8, 11, NULL, 17, 4, 7, NULL, NULL, NULL, 5};
  expect = createTree(resultNodes);
  EXPECT_TRUE(isTreeEqual(result, expect));

  // 示例 3：
  // 输入：root = [1,2,-3,-5,null,4,null], limit = -1
  // 输出：[1,null,-3,4]
  treeNodes = {1, 2, -3, -5, NULL, 4, NULL};
  root = createTree(treeNodes);
  result = solution.sufficientSubset(root, -1);
  resultNodes = {1, NULL, -3, 4};
  expect = createTree(resultNodes);
  EXPECT_TRUE(isTreeEqual(result, expect));
}
