// 完全二叉树插入器
// https://leetcode.cn/problems/complete-binary-tree-inserter
// INLINE  ../images/tree/complete_binary_tree_inserter.jpeg
#include <headers.hpp>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter
{
public:
  CBTInserter(TreeNode *root)
  {
    this->root = root;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
      {
        q.push(node->left);
      }
      if (node->right)
      {
        q.push(node->right);
      }
      if (!(node->left && node->right))
      {
        candidate.push(node);
      }
    }
  }

  int insert(int val)
  {
    TreeNode *child = new TreeNode(val);
    TreeNode *node = candidate.front();
    int ret = node->val;
    if (!node->left)
    {
      node->left = child;
    }
    else
    {
      node->right = child;
      candidate.pop();
    }
    candidate.push(child);
    return ret;
  }

  TreeNode *get_root()
  {
    return root;
  }

private:
  queue<TreeNode *> candidate;
  TreeNode *root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */