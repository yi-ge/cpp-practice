// 翻转二叉树
// https://leetcode.cn/problems/invert-binary-tree/
// INLINE  ../../images/tree/invert_binary_tree.jpeg

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
  // 翻转二叉树的函数
  TreeNode *invertTree(TreeNode *root) {
    // 如果节点为空，直接返回空
    if (root == nullptr) {
      return nullptr;
    }

    // 翻转左子树
    TreeNode *left = invertTree(root->left);
    // 翻转右子树
    TreeNode *right = invertTree(root->right);
    // 交换左右子树
    root->left = right;
    root->right = left;

    // 返回翻转后的树
    return root;
  }
};