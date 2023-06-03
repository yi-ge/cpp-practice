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
  // 递归函数，判断以root为根的子树是否为二叉搜索树，lower和upper分别代表当前节点的上界和下界
  bool isValidBST(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr) // 如果是空树，返回true
      return true;

    if (root->val <= lower ||
        root->val >= upper) { // 如果当前节点不在上下界范围内，返回false
      return false;
    }

    // 递归判断左右子树是否为二叉搜索树
    return isValidBST(root->left, lower,
                      root->val) && // 左子树的上界更新为root的值，下界不变
           isValidBST(root->right, root->val,
                      upper); // 右子树的下界更新为root的值，上界不变
  }

  bool isValidBST(TreeNode *root) {
    return isValidBST(root, LONG_MIN,
                      LONG_MAX); // 调用递归函数，判断整棵树是否为二叉搜索树
  }
};