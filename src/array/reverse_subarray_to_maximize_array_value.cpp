// 翻转子数组得到最大的数组值
// https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value
// INLINE  ../../images/array/reverse_subarray_to_maximize_array_value.jpeg
// 题目理解有难度。
#include <headers.hpp>

class Solution {
public:
  int maxValueAfterReverse(vector<int> &nums) {
    int base = 0, d = 0, mx = INT_MIN, mn = INT_MAX, n = nums.size();
    for (int i = 1; i < n; i++) {
      int a = nums[i - 1], b = nums[i];
      base += abs(a - b);
      mx = max(mx, min(a, b));
      mn = min(mn, max(a, b));
      d = max(d, max(abs(nums[0] - b) - abs(a - b),       // i=0
                     abs(nums[n - 1] - a) - abs(a - b))); // j=n-1
    }
    return base + max(d, 2 * (mx - mn));
  }
};