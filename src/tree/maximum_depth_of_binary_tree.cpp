// 二叉树的最大深度
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// INLINE  ../../images/tree/maximum_depth_of_binary_tree.jpeg
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
  // 计算二叉树的最大深度
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    // 递归计算左子树和右子树的最大深度，取较大值加一即为整个二叉树的最大深度
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};