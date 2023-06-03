// 特殊数组的特征值
// https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x
// INLINE
// ../../images/array/special_array_with_x_elements_greater_than_or_equal_x.jpeg
// 解题思路：本地画图模拟
#include <headers.hpp>

class Solution {
public:
  int specialArray(vector<int> &nums) {
    sort(nums.begin(), nums.end()); // 先将数组排序
    int n = nums.size();
    for (int i = 0; i < n; i++) { // 遍历数组
      int res = n - i;            // 计算特征值
      if (nums[i] >= res &&
          (i - 1 < 0 || nums[i - 1] < res)) { // 判断是否符合条件
        return res;                           // 返回特征值
      }
    }
    return -1; // 找不到符合条件的特征值，返回-1
  }
};