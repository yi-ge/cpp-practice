// 二叉搜索树中的搜索
// https://leetcode.cn/problems/search-in-a-binary-search-tree/
// INLINE  ../../images/tree/search_in_a_binary_search_tree.jpeg
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
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr)
      return nullptr;
    if (root->val == val)
      return root;
    return searchBST(val < root->val ? root->left : root->right, val);
  }
};