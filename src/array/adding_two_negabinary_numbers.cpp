// 负二进制数相加
// https://leetcode.cn/problems/adding-two-negabinary-numbers
// INLINE  ../../images/array/adding_two_negabinary_numbers.jpeg
// 参见官方题解
#include <headers.hpp>

// class Solution {
// public:
//   vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
//     int i = arr1.size() - 1, j = arr2.size() - 1;
//     int carry = 0;
//     vector<int> ans;
//     while (i >= 0 || j >= 0 || carry) {
//       int x = carry;
//       if (i >= 0)
//         x += arr1[i--];
//       if (j >= 0)
//         x += arr2[j--];

//       ans.push_back((x + 2) % 2);
//       carry = -(x / 2);
//     }
//     while (ans.size() > 1 && ans.back() == 0) {
//       ans.pop_back();
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
//   }
// };

class Solution {
public:
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    // i 和 j 分别是 arr1 和 arr2 的最后一个元素的下标
    int i = arr1.size() - 1, j = arr2.size() - 1;
    // carry 用来存储进位
    int carry = 0;
    // ans 是结果数组
    vector<int> ans;
    // 循环直到 i 和 j 都小于 0（没有更多的数字要相加）并且 carry 为
    // 0（没有更多的进位）
    while (i >= 0 || j >= 0 || carry) {
      // x 是当前数字与进位的和
      int x = carry;
      // 如果 arr1 还有更多的数字，加上当前数字
      if (i >= 0) {
        x += arr1[i];
      }
      // 如果 arr2 还有更多的数字，加上当前数字
      if (j >= 0) {
        x += arr2[j];
      }
      // 如果 x 大于或等于 2，我们需要减去 2 并设置 carry 为 -1
      if (x >= 2) {
        ans.push_back(x - 2);
        carry = -1;
        // 如果 x 大于或等于 0，我们不需要做任何事情并设置 carry 为 0
      } else if (x >= 0) {
        ans.push_back(x);
        carry = 0;
        // 如果 x 为负数，我们需要加上 2 并设置 carry 为 1
      } else {
        ans.push_back(1);
        carry = 1;
      }
      // 递减 i 和 j
      --i;
      --j;
    }
    // 移除前导零
    while (ans.size() > 1 && ans.back() == 0) {
      ans.pop_back();
    }
    // 反转数组
    reverse(ans.begin(), ans.end());
    return ans;
  }
};