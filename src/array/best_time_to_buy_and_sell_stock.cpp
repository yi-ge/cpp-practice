// 买卖股票的最佳时机
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// INLINE  ../../images/array/best_time_to_buy_and_sell_stock.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minPrice = 1e9;
    int maxProfit = 0;
    for (int price : prices) {
      maxProfit = max(maxProfit, price - minPrice);
      minPrice = min(minPrice, price);
    }

    return maxProfit;
  }
};