// 二叉树最大宽度
// https://leetcode.cn/problems/maximum-width-of-binary-tree
// INLINE  ../../images/tree/maximum_width_of_binary_tree.jpeg
#include <headers.hpp>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    unsigned long long ans = 1;
    vector<pair<TreeNode *, unsigned long long>> arr;
    arr.emplace_back(root, 1L);

    while (!arr.empty())
    {
      vector<pair<TreeNode *, unsigned long long>> temp;
      for (auto &[node, index] : arr)
      {
        if (node->left)
        {
          temp.emplace_back(node->left, index * 2);
        }

        if (node->right)
        {
          temp.emplace_back(node->right, index * 2 + 1);
        }
      }
      ans = max(ans, arr.back().second - arr[0].second + 1);
      arr = move(temp);
    }

    return ans;
  }
};