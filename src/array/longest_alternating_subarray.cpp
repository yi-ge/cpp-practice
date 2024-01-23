// 最长交替子数组
// https://leetcode.cn/problems/longest-alternating-subarray
// INLINE  ../../images/array/longest_alternating_subarray.jpeg

#include <headers.hpp>

class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int res = -1;
    int n = nums.size();
    for (int firstIndex = 0; firstIndex < n; firstIndex++) {
      for (int i = firstIndex + 1; i < n; i++) {
        int length = i - firstIndex + 1;
        if (nums[i] - nums[firstIndex] == (length - 1) % 2) {
          res = max(res, length);
        } else {
          break;
        }
      }
    }
    return res;
  }
};