// 寻找重复的子树
// https://leetcode-cn.com/problems/find-duplicate-subtrees
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  string dfs(TreeNode *node) {
    if (node == nullptr)
      return ""; // 边界条件，当结点为空时返回空字符串

    string s =
        to_string(node->val) + " " + dfs(node->left) + " " + dfs(node->right);

    if (++umap[s] == 2)
      ans.push_back(node); // 当根节点为node的子树出现两次时加入答案数组
    return s;
  }
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    dfs(root);  // 深度优先搜索
    return ans; // 返回结果数组
  }

private:
  unordered_map<string, int> umap; // 建立哈希映射表
  vector<TreeNode *> ans;          // 存储结果数组
};