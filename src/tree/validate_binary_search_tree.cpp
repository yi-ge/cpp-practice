// 验证二叉搜索树
// https://leetcode.cn/problems/validate-binary-search-tree/
// INLINE  ../../images/tree/validate_binary_search_tree.jpeg
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
  bool isValidBST(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr)
      return true;

    if (root->val <= lower || root->val >= upper) {
      return false;
    }

    return isValidBST(root->left, lower, root->val) &&
           isValidBST(root->right, root->val, upper);
  }

  bool isValidBST(TreeNode *root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }
};