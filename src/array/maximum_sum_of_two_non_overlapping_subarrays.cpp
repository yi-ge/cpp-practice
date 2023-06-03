// 两个非重叠子数组的最大和
// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays
// INLINE  ../../images/array/maximum_sum_of_two_non_overlapping_subarrays.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size(); // 数组长度
    vector<int> prefixSum(n + 1, 0); // 前缀和数组
    for (int i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + nums[i]; // 计算前缀和
    }
    int res = 0;
    // 枚举第一个子数组的起始位置和第二个子数组的起始位置
    for (int i = 0; i + firstLen + secondLen <= n; ++i) {
      for (int j = i + firstLen; j + secondLen <= n; ++j) {
        // 计算两个子数组的和，并更新最大值
        res = max(res, prefixSum[i + firstLen] - prefixSum[i] +
                           prefixSum[j + secondLen] - prefixSum[j]);
      }
    }
    // 枚举第二个子数组的起始位置和第一个子数组的起始位置
    for (int i = 0; i + firstLen + secondLen <= n; ++i) {
      for (int j = i + secondLen; j + firstLen <= n; ++j) {
        // 计算两个子数组的和，并更新最大值
        res = max(res, prefixSum[i + secondLen] - prefixSum[i] +
                           prefixSum[j + firstLen] - prefixSum[j]);
      }
    }
    return res; // 返回最大和
  }
};