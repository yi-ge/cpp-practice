// 最大层内元素和
// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree
// INLINE  ../images/tree/maximum_level_sum_of_a_binary_tree.jpeg
// 层序遍历
#include <headers.hpp>

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    int layer = 0, maxSum = root->val, level = 1;
    vector<TreeNode *> q = {root};
    while (!q.empty())
    {
      vector<TreeNode *> nq;
      int sum = 0;
      for (auto node : q)
      {
        sum += node->val;
        if (node->left)
          nq.emplace_back(node->left);
        if (node->right)
          nq.emplace_back(node->right);
      }
      if (sum > maxSum)
      {
        maxSum = sum;
        layer = level;
      }
      q = move(nq);
      ++level;
    }

    return layer;
  }
};