// 礼盒的最大甜蜜度
// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket
// INLINE  ../../images/sort/maximum_tastiness_of_candy_basket.jpeg
#include <headers.hpp>

class Solution {
public:
  int maximumTastiness(vector<int> &price, int k) {
    // 对价格进行排序
    sort(price.begin(), price.end());
    // 获取商品数量
    int n = price.size();
    // 定义二分搜索范围的左右边界
    int left = 0, right = price[n - 1] - price[0];
    // 在[left, right]范围内进行二分搜索
    while (left < right) {
      // 获取二分搜索范围的中间值
      int mid = (left + right + 1) >> 1;
      // 检查是否可以以mid的美味度购买至少k件商品
      if (check(price, k, mid)) {
        // 如果可以，更新二分搜索范围的左边界
        left = mid;
      } else {
        // 否则，更新二分搜索范围的右边界
        right = mid - 1;
      }
    }
    // 返回最大美味度
    return left;
  }

  bool check(const vector<int> &price, int k, int tastiness) {
    // 初始化前一件商品的价格为最小整数
    int prev = INT_MIN >> 1;
    // 初始化购买的商品数量为0
    int cnt = 0;
    // 遍历商品
    for (int p : price) {
      // 如果当前商品的价格减去前一件商品的价格大于等于美味度
      if (p - prev >= tastiness) {
        // 增加购买的商品数量
        cnt++;
        // 更新前一件商品的价格
        prev = p;
      }
    }
    // 检查是否可以购买至少k件商品
    return cnt >= k;
  }
};