// 公因子的数目
// https://leetcode.cn/problems/number-of-common-factors
// INLINE  ../../images/math/number_of_common_factors.jpeg
#include <headers.hpp>

class Solution {
public:
  int commonFactors(int a, int b) {
    int ans = 0;
    for (int i = 1; i <= min(a, b); i++) {
      if (a % i == 0 && b % i == 0) {
        ans++;
      }
    }
    return ans;
  }
};