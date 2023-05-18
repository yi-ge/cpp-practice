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
    int i = arr1.size() - 1, j = arr2.size() - 1;
    int carry = 0;
    vector<int> ans;
    while (i >= 0 || j >= 0 || carry) {
      int x = carry;
      if (i >= 0) {
        x += arr1[i];
      }
      if (j >= 0) {
        x += arr2[j];
      }
      if (x >= 2) {
        ans.push_back(x - 2);
        carry = -1;
      } else if (x >= 0) {
        ans.push_back(x);
        carry = 0;
      } else {
        ans.push_back(1);
        carry = 1;
      }
      --i;
      --j;
    }
    while (ans.size() > 1 && ans.back() == 0) {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
