// 经营摩天轮的最大利润
// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel
// INLINE ../../images/array/maximum_profit_of_operating_a_centennial_wheel.jpeg

#include <headers.hpp>

class Solution {
public:
  int minOperationsMaxProfit(vector<int> &customers, int boardingCost,
                             int runningCost) {
    int profit = 0;
    int maxProfit = 0;
    int maxProfitRound = -1;
    int waiting = 0;
    int round = 0;
    for (int customer : customers) {
      waiting += customer;
      int boarding = min(4, waiting);
      waiting -= boarding;
      profit += boarding * boardingCost - runningCost;
      round++;
      if (profit > maxProfit) {
        maxProfit = profit;
        maxProfitRound = round;
      }
    }
    while (waiting > 0) {
      int boarding = min(4, waiting);
      waiting -= boarding;
      profit += boarding * boardingCost - runningCost;
      round++;
      if (profit > maxProfit) {
        maxProfit = profit;
        maxProfitRound = round;
      }
    }
    return maxProfitRound;
  }
};