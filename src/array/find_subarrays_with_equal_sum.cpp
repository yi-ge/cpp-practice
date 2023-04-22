// 和相等的子数组
// https://leetcode.cn/problems/find-subarrays-with-equal-sum
// INLINE  ../../images/array/find_subarrays_with_equal_sum.jpeg
#include <headers.hpp>

class Solution {
public:
  bool findSubarrays(std::vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return false;
    }

    std::unordered_map<int, int> sum_count;
    for (int i = 0; i < n - 1; ++i) {
      int sum = nums[i] + nums[i + 1];
      sum_count[sum]++;
    }

    for (const auto &pair : sum_count) {
      if (pair.second >= 2) {
        return true;
      }
    }

    return false;
  }
};