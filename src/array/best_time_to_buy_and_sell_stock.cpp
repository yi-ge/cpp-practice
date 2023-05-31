// 买卖股票的最佳时机
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// INLINE  ../../images/array/best_time_to_buy_and_sell_stock.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // 初始化最大利润为 0
    int maxProfit = 0;

    // 初始化最低价格为一个很大的数
    int minPrice = 1e9;

    // 遍历价格数组，更新最大利润和最低价格
    for (int price : prices) {
      maxProfit = max(maxProfit, price - minPrice);
      minPrice = min(minPrice, price);
    }

    // 返回最大利润
    return maxProfit;
  }
};