// 公因子的数目
// https://leetcode.cn/problems/number-of-common-factors
// INLINE  ../../images/math/number_of_common_factors.jpeg
#include <headers.hpp>

class Solution {
public:
  int commonFactors(int a, int b) {
    int ans = 0;                           // 初始化公因子数为0
    for (int i = 1; i <= min(a, b); i++) { // 从1到a和b中的最小值开始遍历
      if (a % i == 0 && b % i == 0) {      // 如果i是a和b的公因子
        ans++;                             // 公因子数加1
      }
    }
    return ans; // 返回公因子数
  }
};