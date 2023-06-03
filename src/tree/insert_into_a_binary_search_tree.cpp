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
  // 插入节点
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }
    TreeNode *pos = root;
    while (pos != nullptr) {
      if (val < pos->val) { // 待插入节点值小于当前节点值，向左子树寻找插入位置
        if (pos->left == nullptr) { // 左子树为空，插入节点
          pos->left = new TreeNode(val);
          break;
        } else { // 左子树不为空，继续向左子树寻找插入位置
          pos = pos->left;
        }
      } else { // 待插入节点值大于等于当前节点值，向右子树寻找插入位置
        if (pos->right == nullptr) { // 右子树为空，插入节点
          pos->right = new TreeNode(val);
          break;
        } else { // 右子树不为空，继续向右子树寻找插入位置
          pos = pos->right;
        }
      }
    }

    return root;
  }
};