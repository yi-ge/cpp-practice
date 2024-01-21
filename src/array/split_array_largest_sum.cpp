// 分割数组的最大值
// https://leetcode.cn/problems/split-array-largest-sum
// INLINE  ../../images/array/split_array_largest_sum.jpeg

#include <headers.hpp>

class Solution {
public:
  int split(vector<int> &nums, int max) {
    int count = 1;
    int sum = 0;
    for (int num : nums) {
      if (sum + num > max) {
        count++;
        sum = num;
      } else {
        sum += num;
      }
    }
    return count;
  }
  int splitArray(vector<int> &nums, int k) {
    int left = 0, right = 0;
    for (int num : nums) {
      left = max(left, num);
      right += num;
    }
    while (left < right) {
      int mid = left + (right - left) / 2;
      int count = split(nums, mid);
      if (count <= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};