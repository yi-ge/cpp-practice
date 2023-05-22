// 根到叶路径上的不足节点
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths
// INLINE  ../../images/tree/insufficient_nodes_in_root_to_leaf_paths.jpeg
// 官方题解：https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/solution/gen-dao-xie-lu-jing-shang-de-bu-zu-jie-d-f4vz/
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
  // bool dfs(TreeNode *&root, int sum, int limit) {
  //   if (!root) {
  //     return false;
  //   }

  //   sum += root->val;

  //   if (!root->left && !root->right) {
  //     return sum < limit;
  //   }

  //   bool left_remove = dfs(root->left, sum, limit);
  //   bool right_remove = dfs(root->right, sum, limit);

  //   if (left_remove) {
  //     delete root->left;
  //     root->left = nullptr;
  //   }
  //   if (right_remove) {
  //     delete root->right;
  //     root->right = nullptr;
  //   }

  //   return (!root->left && !root->right);
  // }

  // TreeNode *sufficientSubset(TreeNode *root, int limit) {
  //   if (dfs(root, 0, limit)) {
  //     delete root;
  //     return nullptr;
  //   } else {
  //     return root;
  //   }
  // }
  bool checkSufficientLeaf(TreeNode *node, int sum, int limit) {
    if (!node) {
      return false;
    }
    if (node->left == nullptr && node->right == nullptr) {
      return node->val + sum >= limit;
    }
    bool haveSufficientLeft =
        checkSufficientLeaf(node->left, sum + node->val, limit);
    bool haveSufficientRight =
        checkSufficientLeaf(node->right, sum + node->val, limit);
    if (!haveSufficientLeft) {
      node->left = nullptr;
    }
    if (!haveSufficientRight) {
      node->right = nullptr;
    }
    return haveSufficientLeft || haveSufficientRight;
  }

  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    bool haveSufficient = checkSufficientLeaf(root, 0, limit);
    return haveSufficient ? root : nullptr;
  }
};