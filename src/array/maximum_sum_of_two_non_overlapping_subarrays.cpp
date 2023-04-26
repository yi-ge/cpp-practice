// 两个非重叠子数组的最大和
// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays
// INLINE  ../../images/array/maximum_sum_of_two_non_overlapping_subarrays.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    int res = 0;
    for (int i = 0; i + firstLen + secondLen <= n; ++i) {
      for (int j = i + firstLen; j + secondLen <= n; ++j) {
        res = max(res, prefixSum[i + firstLen] - prefixSum[i] +
                           prefixSum[j + secondLen] - prefixSum[j]);
      }
    }
    for (int i = 0; i + firstLen + secondLen <= n; ++i) {
      for (int j = i + secondLen; j + firstLen <= n; ++j) {
        res = max(res, prefixSum[i + secondLen] - prefixSum[i] +
                           prefixSum[j + firstLen] - prefixSum[j]);
      }
    }
    return res;
  }
};