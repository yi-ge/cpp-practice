// 两数之和 IV
// https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/
// INLINE  ../../images/tree/two_sum_iv_input_is_a_bst.jpeg
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
private:
  unordered_set<int> hashSet;

public:
  bool findTarget(TreeNode *root, int k) {
    if (root == nullptr)
      return false;

    if (hashSet.count(k - root->val))
      return true;

    hashSet.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};