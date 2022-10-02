// 二叉搜索树的最近公共祖先
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
// INLINE  ../../images/tree/lowest_common_ancestor_of_a_binary_search_tree.jpeg
#include <headers.hpp>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // 参考：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-3c/
    // 如果根节点和p,q的差相乘是正数，说明这两个差值要么都是正数要么都是负数，也就是说
    // 他们肯定都位于根节点的同一侧，就继续往下找
    // 如果小于等于0，说明p和q位于root的两侧
    return long(root->val - p->val) * long(root->val - q->val) <= 0
               ? root
               : lowestCommonAncestor(
                     p->val < root->val ? root->left : root->right, p, q);
  }
};