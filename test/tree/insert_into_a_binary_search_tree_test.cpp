#include "tree_node.hpp"
#include <tree/insert_into_a_binary_search_tree.cpp>

TEST(二叉搜索树中的插入操作, TreeNode) {
  // 示例 1：
  // 输入：root = [4,2,7,1,3], val = 5
  // 输出：[4,2,7,1,3,5]
  // 解释：另一个满足题目要求可以通过的树是：
  Solution solution;
  vector<int> treeNodes = {4, 2, 7, 1, 3};
  vector<int> resNodes = {4, 2, 7, 1, 3, 5};
  TreeNode *root = createTree(treeNodes);
  TreeNode *res = createTree(resNodes);
  EXPECT_EQ(treeToString(solution.insertIntoBST(root, 5)), treeToString(res));

  // 示例 2：
  // 输入：root = [40,20,60,10,30,50,70], val = 25
  // 输出：[40,20,60,10,30,50,70,null,null,25]
  vector<int> treeNodes2 = {40, 20, 60, 10, 30, 50, 70};
  vector<int> resNodes2 = {40, 20, 60, 10, 30, 50, 70, NULL, NULL, 25};
  TreeNode *root2 = createTree(treeNodes2);
  TreeNode *res2 = createTree(resNodes2);
  EXPECT_EQ(treeToString(solution.insertIntoBST(root2, 25)),
            treeToString(res2));

  // 示例 3：
  // 输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
  // 输出：[4,2,7,1,3,5]
  vector<int> treeNodes3 = {4, 2, 7, 1, 3, NULL, NULL, NULL, NULL, NULL, NULL};
  vector<int> resNodes3 = {4, 2, 7, 1, 3, 5};
  TreeNode *root3 = createTree(treeNodes3);
  TreeNode *res3 = createTree(resNodes3);
  EXPECT_EQ(treeToString(solution.insertIntoBST(root3, 5)), treeToString(res3));

  // 示例 4：
  // 输入：root = [], val = 10
  // 输出：[10]
  TreeNode *root4 = nullptr;
  TreeNode *res4 = new TreeNode(10);
  EXPECT_EQ(treeToString(solution.insertIntoBST(root4, 10)),
            treeToString(res4));

  // 示例 5：
  // 输入：root = [1, 2], val = 3
  // 输出：[1, 2, 3]
  vector<int> treeNodes5 = {1, 2};
  vector<int> resNodes5 = {1, 2, 3};
  TreeNode *root5 = createTree(treeNodes5);
  TreeNode *res5 = createTree(resNodes5);
  EXPECT_EQ(treeToString(solution.insertIntoBST(root5, 3)), treeToString(res5));
}
