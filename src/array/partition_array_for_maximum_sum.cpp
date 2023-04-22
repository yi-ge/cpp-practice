// 分隔数组以得到最大和
// https://leetcode.cn/problems/partition-array-for-maximum-sum
// INLINE  ../../images/array/partition_array_for_maximum_sum.jpeg
#include <headers.hpp>

class Solution {
public:
  using ll = long long;

  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1); // Dynamic programming table to store the maximum sum

    // Iterate through the array
    for (int i = 1; i <= n; i++) {
      int maxValInPartition =
          arr[i - 1]; // Initialize max value in the current partition

      // Iterate in reverse from current position (i) up to k elements back
      for (int j = i - 1; j >= 0 && j >= i - k; j--) {
        // Update the maximum sum by comparing the current value to the sum of
        // the previous partition
        dp[i] = max(dp[i], dp[j] + maxValInPartition * (i - j));

        // Update maxValInPartition if there is still an element in the
        // partition
        if (j > 0) {
          maxValInPartition = max(maxValInPartition, arr[j - 1]);
        }
      }
    }

    return dp[n]; // Return the maximum sum after partitioning
  }
};
