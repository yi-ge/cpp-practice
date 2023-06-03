// 最大层内元素和
// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree
// INLINE  ../../images/tree/maximum_level_sum_of_a_binary_tree.jpeg
// 层序遍历
#include <headers.hpp>

class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    int layer = 1, maxSum = root->val,
        level = 1; // 初始化层数为1，最大和为根节点值，当前层数为1
    vector<TreeNode *> q = {root}; // 建立树的队列，初始值为根节点
    while (!q.empty())             // 当队列不为空时，继续循环
    {
      vector<TreeNode *> nq; // 下一层节点的队列
      int sum = 0;           // 当前层节点的和
      for (auto node : q)    // 遍历当前层的所有节点
      {
        sum += node->val; // 计算当前层节点的和
        if (node->left) // 如果当前节点有左子节点，则将左子节点加入下一层节点队列
          nq.emplace_back(node->left);
        if (node->right) // 如果当前节点有右子节点，则将右子节点加入下一层节点队列
          nq.emplace_back(node->right);
      }
      if (sum > maxSum) // 如果当前层的节点和大于最大和
      {
        maxSum = sum;  // 更新最大和
        layer = level; // 更新最大和的层数
      }
      q = move(nq); // 将下一层节点队列的值赋给当前层节点队列，进行下一次循环
      ++level;      // 层数加1
    }

    return layer; // 返回最大和的层数
  }
};