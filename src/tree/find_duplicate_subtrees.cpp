// 寻找重复的子树
// https://leetcode.cn/problems/find-duplicate-subtrees
// INLINE  ../../images/tree/find_duplicate_subtrees.jpeg
#include <headers.hpp>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  string dfs(TreeNode *node)
  {
    if (node == nullptr)
      return ""; // 边界条件

    string s = to_string(node->val) + " " + dfs(node->left) + " " + dfs(node->right);

    if (++umap[s] == 2)
      ans.push_back(node);
    return s;
  }
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    dfs(root);
    return ans;
  }

private:
  unordered_map<string, int> umap;
  vector<TreeNode *> ans;
};