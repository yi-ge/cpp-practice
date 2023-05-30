// 删点成林
// https://leetcode.cn/problems/delete-nodes-and-return-forest
// INLINE  ../../images/tree/delete_nodes_and_return_forest.jpeg
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
  TreeNode *dfs(TreeNode *root, unordered_set<int> &to_delete_set,
                vector<TreeNode *> &res) {
    if (!root) {
      return nullptr;
    }
    root->left = dfs(root->left, to_delete_set, res);
    root->right = dfs(root->right, to_delete_set, res);
    if (to_delete_set.find(root->val) != to_delete_set.end()) {
      if (root->left) {
        res.push_back(root->left);
      }
      if (root->right) {
        res.push_back(root->right);
      }
      return nullptr;
    }
    return root;
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> res;
    unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
    root = dfs(root, to_delete_set, res);
    if (root) {
      res.push_back(root);
    }
    return res;
  }
};