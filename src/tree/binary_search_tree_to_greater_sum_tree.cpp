// 从二叉搜索树到更大和树
// https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree
// INLINE  ../../images/tree/binary_search_tree_to_greater_sum_tree.jpeg

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
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    return bstToGstHelper(root, sum);
  }

private:
  TreeNode *bstToGstHelper(TreeNode *root, int &sum) {
    if (root != nullptr) {
      bstToGstHelper(root->right, sum);
      sum += root->val;
      root->val = sum;
      bstToGstHelper(root->left, sum);
    }
    return root;
  }
};