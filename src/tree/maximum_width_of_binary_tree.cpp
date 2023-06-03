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

// 解法：二叉树的层序遍历，使用 pair 存储每个节点的 index，index 的计算方法是左子节点 index * 2，右子节点 index * 2 + 1
class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    unsigned long long ans = 1; // 初始化答案
    vector<pair<TreeNode *, unsigned long long>> arr; // 使用 pair 存储每个节点的指针和 index
    arr.emplace_back(root, 1L); // 将根节点和 index = 1 存入数组中

    while (!arr.empty()) // 一直循环直到数组为空
    {
      vector<pair<TreeNode *, unsigned long long>> temp; // 创建临时数组
      for (auto &[node, index] : arr) // 遍历当前数组的所有节点
      {
        if (node->left) // 如果有左子节点
        {
          temp.emplace_back(node->left, index * 2); // 将左子节点和新的 index 存入临时数组
        }

        if (node->right) // 如果有右子节点
        {
          temp.emplace_back(node->right, index * 2 + 1); // 将右子节点和新的 index 存入临时数组
        }
      }
      ans = max(ans, arr.back().second - arr[0].second + 1); // 更新最大宽度
      arr = move(temp); // 将临时数组赋值给当前数组，进入下一层循环
    }

    return ans; // 返回最大宽度
  }
};