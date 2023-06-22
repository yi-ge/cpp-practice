// 可被三整除的最大和
// https://leetcode.cn/problems/greatest-sum-divisible-by-three
// INLINE  ../../images/sort/greatest_sum_divisible_by_three.jpeg

#include <headers.hpp>

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    vector<int> dp(3, 0);
    for (auto &num : nums) {
      vector<int> tmp = dp;
      for (auto &sum : tmp) {
        sum += num;
      }
      for (auto &sum : tmp) {
        dp[sum % 3] = max(dp[sum % 3], sum);
      }
    }
    return dp[0];
  }
};