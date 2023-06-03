// 路径总和
// https://leetcode.cn/problems/path-sum/
// INLINE  ../../images/tree/path_sum.jpeg
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
  // 判断是否存在从根节点到叶子节点路径和为目标值的路径
  bool hasPathSum(TreeNode *root, int targetSum) {
    // 空树不满足条件，返回 false
    if (root == nullptr) {
      return false;
    }

    // 只有一个根节点，判断根节点的值是否等于目标值
    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == root->val;
    }

    // 递归判断左子树和右子树是否有满足条件的路径
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};