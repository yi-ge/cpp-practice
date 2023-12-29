// 购买两块巧克力
// https://leetcode.cn/problems/buy-two-chocolates
// INLINE  ../../images/sort/buy_two_chocolates.jpeg

#include <headers.hpp>

class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    int fi = INT_MAX;
    int se = INT_MAX;
    for (int p : prices) {
      if (p < fi) {
        se = fi;
        fi = p;
      } else if (p < se) {
        se = p;
      }
    }
    if (money < fi + se) {
      return money;
    } else {
      return money - fi - se;
    }
  }
};
