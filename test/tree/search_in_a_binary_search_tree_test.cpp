#include "tree_node.hpp"
#include <tree/search_in_a_binary_search_tree.cpp>

TEST(二叉搜索树中的搜索, TreeNode) {
  // 示例 1:
  // 输入：root = [4,2,7,1,3], val = 2
  // 输出：[2,1,3]
  Solution solution;
  vector<int> treeNodes = {4, 2, 7, 1, 3};
  TreeNode *root = createTree(treeNodes);
  vector<int> val = {2, 1, 3};
  TreeNode *searchResult = createTree(val);
  EXPECT_EQ(treeToString(solution.searchBST(root, 2)),
            treeToString(searchResult));

  // 示例 2:
  // 输入：root = [4,2,7,1,3], val = 5
  // 输出：[]
  vector<int> treeNodes2 = {4, 2, 7, 1, 3};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_EQ(solution.searchBST(root2, 5), nullptr);
}
