#include <tree/maximum_level_sum_of_a_binary_tree.cpp>

TEST(最大层内元素和, maxLevelSum)
{
  // 示例 1：
  // 输入：root = [1,7,0,7,-8,null,null]
  // 输出：2
  Solution solution;
  vector<int> treeNodes = {1, 7, 0, 7, -8, NULL, NULL};
  TreeNode *root = createTree(treeNodes);
  EXPECT_EQ(solution.maxLevelSum(root), 2);

  // 示例 2：
  // 输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
  // 输出：2
  vector<int> treeNodes2 = {989, NULL, 10250, 98693, -89388, NULL, NULL, NULL, -32127};
  TreeNode *root2 = createTree(treeNodes2);
  EXPECT_EQ(solution.maxLevelSum(root2), 2);

  // 示例 3：
  // 输入：root = [1]
  // 输出：1
  vector<int> treeNodes3 = {1};
  TreeNode *root3 = createTree(treeNodes3);
  EXPECT_EQ(solution.maxLevelSum(root3), 1);
}
