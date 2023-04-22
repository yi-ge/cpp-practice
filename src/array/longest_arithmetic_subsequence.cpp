// 最长等差数列
// https://leetcode.cn/problems/longest-arithmetic-subsequence
// INLINE  ../../images/array/longest_arithmetic_subsequence.jpeg
#include <headers.hpp>

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    int ans = 2;
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int d = nums[j] - nums[i];
        if (dp[i].count(d)) {
          dp[j][d] = dp[i][d] + 1;
        } else {
          dp[j][d] = 2;
        }
        ans = max(ans, dp[j][d]);
      }
    }
    return ans;
  }
};