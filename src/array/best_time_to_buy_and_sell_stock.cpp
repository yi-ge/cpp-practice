// 买卖股票的最佳时机
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
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
      // 更新最大利润，当前价格减去之前的最低价格
      maxProfit = max(maxProfit, price - minPrice);
      // 更新最低价格，如果当前价格比之前的最低价格还低，则更新为当前价格
      minPrice = min(minPrice, price);
    }

    // 返回最大利润
    return maxProfit;
  }
};