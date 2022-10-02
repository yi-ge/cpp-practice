// 二叉搜索树中的插入操作
// https://leetcode.cn/problems/insert-into-a-binary-search-tree/
// INLINE  ../../images/tree/insert_into_a_binary_search_tree.jpeg
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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }
    TreeNode *pos = root;
    while (pos != nullptr) {
      if (val < pos->val) {
        if (pos->left == nullptr) {
          pos->left = new TreeNode(val);
          break;
        } else {
          pos = pos->left;
        }
      } else {
        if (pos->right == nullptr) {
          pos->right = new TreeNode(val);
          break;
        } else {
          pos = pos->right;
        }
      }
    }

    return root;
  }
};