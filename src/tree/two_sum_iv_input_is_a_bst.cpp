// 两数之和 IV
// https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/
// INLINE  ../../images/tree/two_sum_iv_input_is_a_bst.jpeg
#include <headers.hpp>

// class Solution {
// private:
//   std::unordered_set<int> hashSet;

// public:
//   Solution() { hashSet.clear(); }
//   bool findTarget(TreeNode *root, int k) {
//     if (root == nullptr)
//       return false;

//     if (hashSet.count(k - root->val))
//       return true;
//     // if (hashSet.find(k - root->val) != hashSet.end())
//     //   return true;

//     hashSet.insert(root->val);
//     return findTarget(root->left, k) || findTarget(root->right, k);
//   }
// };

// class Solution {
// public:
//   vector<int> vec;
//   void traversal(TreeNode *root) {
//     if (root == nullptr)
//       return;
//     traversal(root->left);
//     vec.push_back(root->val);
//     traversal(root->right);
//   }
//   bool findTarget(TreeNode *root, int k) {
//     vec.clear();
//     traversal(root);
//     int left = 0, right = vec.size() - 1;
//     while (left < right) {
//       if (vec[left] + vec[right] == k)
//         return true;
//       if (vec[left] + vec[right] < k)
//         left++;
//       if (vec[left] + vec[right] > k)
//         right--;
//     }
//     return false;
//   }
// };

class Solution {
public:
  void inorder(TreeNode *root, vector<int> &nums) {
    if (root == nullptr)
      return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
  bool findTarget(TreeNode *root, int k) {
    vector<int> nums;
    inorder(root, nums);
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum < k) {
        left++;
      } else if (sum > k) {
        right--;
      } else {
        return true;
      }
    }
    return false;
  }
};
