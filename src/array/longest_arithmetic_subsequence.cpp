// 最长等差数列
// https://leetcode-cn/problems/longest-arithmetic-subsequence
// INLINE  ../../images/array/longest_arithmetic_subsequence.jpeg
#include <headers.hpp>

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    int ans = 2; // 最小长度为2
    int n = nums.size(); // 数组大小
    vector<unordered_map<int, int>> dp(n); // 定义dp，dp[i][d]表示以i为结尾，差值为d的最长等差数列长度
    for (int i = 0; i < n; i++) { // 枚举结尾
      for (int j = i + 1; j < n; j++) { // 枚举倒数第二个数
        int d = nums[j] - nums[i]; // 求差值
        if (dp[i].count(d)) { // 如果存在以i为结尾，差值为d的等差数列
          dp[j][d] = dp[i][d] + 1; // 那么以j为结尾，差值为d的等差数列长度为dp[i][d]+1
        } else {
          dp[j][d] = 2; // 否则，以j为结尾，差值为d的等差数列长度为2
        }
        ans = max(ans, dp[j][d]); // 更新最长等差数列长度
      }
    }
    return ans; // 返回最长等差数列长度
  }
};