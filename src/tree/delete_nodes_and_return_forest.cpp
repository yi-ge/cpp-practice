// 删点成林
// https://leetcode.cn/problems/delete-nodes-and-return-forest
// INLINE  ../../images/tree/delete_nodes_and_return_forest.jpeg
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
  // dfs函数用于遍历二叉树，并返回新的二叉树根节点
  // 参数to_delete_set表示需要删除的节点的值构成的集合
  // 参数res表示存放被删除的节点的左右子树所构成的森林
  TreeNode *dfs(TreeNode *root, unordered_set<int> &to_delete_set,
                vector<TreeNode *> &res) {
    // 如果当前节点为空，则返回空指针
    if (!root) {
      return nullptr;
    }
    // 递归遍历左子树和右子树
    root->left = dfs(root->left, to_delete_set, res);
    root->right = dfs(root->right, to_delete_set, res);
    // 如果当前节点的值在需要删除的节点的集合中
    if (to_delete_set.find(root->val) != to_delete_set.end()) {
      // 如果当前节点有左子树，则将左子树添加到res中
      if (root->left) {
        res.push_back(root->left);
      }
      // 如果当前节点有右子树，则将右子树添加到res中
      if (root->right) {
        res.push_back(root->right);
      }
      // 返回空指针，表示当前节点已被删除
      return nullptr;
    }
    // 如果当前节点的值不在需要删除的节点的集合中，则返回当前节点
    return root;
  }
  // delNodes函数用于删除给定二叉树中的一些节点，并返回被删除节点的左右子树所构成的森林
  // 参数root表示给定的二叉树的根节点
  // 参数to_delete表示需要删除的节点的值构成的数组
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // 存放被删除的节点的左右子树所构成的森林
    vector<TreeNode *> res;
    // 将需要删除的节点的值构成的数组转换为集合
    unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
    // 调用dfs函数遍历二叉树，并返回新的二叉树根节点
    root = dfs(root, to_delete_set, res);
    // 如果新的二叉树根节点非空，则将其添加到res中
    if (root) {
      res.push_back(root);
    }
    // 返回被删除节点的左右子树所构成的森林
    return res;
  }
};