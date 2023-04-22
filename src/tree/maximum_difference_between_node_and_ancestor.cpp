// 节点与其祖先之间的最大差值
// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor
// INLINE  ../../images/tree/maximum_difference_between_node_and_ancestor.jpeg
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
  pair<int, int> dfs(TreeNode *root, int &max_diff) {
    if (root) {
      int min_val = root->val, max_val = root->val;
      if (root->left) {
        auto [left_min, left_max] = dfs(root->left, max_diff);
        min_val = min(min_val, left_min);
        max_val = max(max_val, left_max);
      }
      if (root->right) {
        auto [right_min, right_max] = dfs(root->right, max_diff);
        min_val = min(min_val, right_min);
        max_val = max(max_val, right_max);
      }
      max_diff = max(max_diff, abs(root->val - min_val));
      max_diff = max(max_diff, abs(root->val - max_val));
      return {min_val, max_val};
    } else {
      return {INT_MAX, INT_MIN}; // LCOV_EXCL_LINE
    }
  }

  int maxAncestorDiff(TreeNode *root) {
    int max_diff = 0;
    dfs(root, max_diff);
    return max_diff;
  }
};
