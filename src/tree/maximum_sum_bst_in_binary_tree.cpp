// 二叉搜索子树的最大键值和
// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree
// INLINE  ../../images/tree/maximum_sum_bst_in_binary_tree.jpeg
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
  std::tuple<bool, int, int, int> dfs(TreeNode *root, int &max_sum) {
    if (root == nullptr) {
      return {true, 0, std::numeric_limits<int>::max(),
              std::numeric_limits<int>::min()};
    }

    auto [left_bst, left_sum, left_min, left_max] = dfs(root->left, max_sum);
    auto [right_bst, right_sum, right_min, right_max] =
        dfs(root->right, max_sum);

    if (left_bst && right_bst && left_max < root->val &&
        root->val < right_min) {
      int sum = left_sum + right_sum + root->val;
      max_sum = std::max(max_sum, sum);
      return {true, sum, std::min(left_min, root->val),
              std::max(right_max, root->val)};
    }

    return {false, -1, std::numeric_limits<int>::max(),
            std::numeric_limits<int>::min()};
  }

  int maxSumBST(TreeNode *root) {
    int max_sum = 0;
    dfs(root, max_sum);
    return max_sum;
  }
};