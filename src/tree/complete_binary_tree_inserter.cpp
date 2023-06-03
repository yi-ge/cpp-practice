// 完全二叉树插入器
// https://leetcode.cn/problems/complete-binary-tree-inserter
// INLINE  ../../images/tree/complete_binary_tree_inserter.jpeg
#include <headers.hpp>

class CBTInserter {
public:
  // 构造函数，初始化根节点和候选节点队列
  CBTInserter(TreeNode *root) {
    this->root = root;

    queue<TreeNode *> q;
    q.push(root);

    // 遍历树，将没有左右子节点的节点加入候选节点队列
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
      if (!(node->left && node->right)) {
        candidate.push(node);
      }
    }
  }

  // 插入新节点，返回被替换的节点的值
  int insert(int val) {
    TreeNode *child = new TreeNode(val);
    TreeNode *node = candidate.front();
    int ret = node->val;
    if (!node->left) {
      node->left = child;
    } else {
      node->right = child;
      candidate.pop();
    }
    candidate.push(child);
    return ret;
  } // LCOV_EXCL_LINE

  // 返回根节点
  TreeNode *get_root() { return root; }

private:
  queue<TreeNode *> candidate; // 候选节点队列
  TreeNode *root; // 根节点
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */