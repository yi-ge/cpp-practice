// 连通两组点的最小成本
// https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points
// INLINE  ../../images/math/minimum_cost_to_connect_two_groups_of_points.jpeg

#include <headers.hpp>

class Solution {
public:
  int connectTwoGroups(vector<vector<int>> &cost) {
    int size1 = cost.size(), size2 = cost[0].size(), m = 1 << size2;
    // 初始化两个动态规划数组
    vector<int> dp(m, INT_MAX / 2), dp1(m);
    // 第一个状态的成本为0
    dp[0] = 0;
    // 遍历每一组点
    for (int i = 1; i <= size1; i++) {
      // 遍历所有可能的状态
      for (int s = 0; s < m; s++) {
        // 初始化dp1[s]为最大值
        dp1[s] = INT_MAX / 2;
        // 遍历每一点
        for (int k = 0; k < size2; k++) {
          // 如果第k点未被选中，则跳过
          if ((s & (1 << k)) == 0) {
            continue;
          }
          // 更新dp1[s]
          dp1[s] = min(dp1[s], dp1[s ^ (1 << k)] + cost[i - 1][k]);
          dp1[s] = min(dp1[s], dp[s] + cost[i - 1][k]);
          dp1[s] = min(dp1[s], dp[s ^ (1 << k)] + cost[i - 1][k]);
        }
      }
      // 更新dp数组
      dp.swap(dp1);
    }
    // 返回最小成本
    return dp[m - 1];
  }
};