// 使用最小花费爬楼梯
// https://leetcode.cn/problems/min-cost-climbing-stairs
// INLINE  ../../images/array/min_cost_climbing_stairs.jpeg

#include <headers.hpp>

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int size = cost.size();
    vector<int> dp(size + 1, 0);
    for (int i = 2; i <= size; ++i) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[size];
  }
};