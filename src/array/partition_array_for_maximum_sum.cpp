// 分隔数组以得到最大和
// https://leetcode.cn/problems/partition-array-for-maximum-sum
// INLINE  ../../images/array/partition_array_for_maximum_sum.jpeg
#include <headers.hpp>

class Solution {
public:
  using ll = long long;

  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1); // 动态规划表，用于存储最大和

    // 遍历数组
    for (int i = 1; i <= n; i++) {
      int maxValInPartition = arr[i - 1]; // 初始化当前分区的最大值为当前值

      // 从当前位置(i)向前遍历k个元素
      for (int j = i - 1; j >= 0 && j >= i - k; j--) {
        // 通过比较当前值和之前分区的和来更新最大和
        dp[i] = max(dp[i], dp[j] + maxValInPartition * (i - j));

        // 如果分区中仍有元素，则更新最大值
        if (j > 0) {
          maxValInPartition = max(maxValInPartition, arr[j - 1]);
        }
      }
    }

    return dp[n]; // 返回分隔后的最大和
  }
};