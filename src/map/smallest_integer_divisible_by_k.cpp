// 可被 K 整除的最小整数
// https://leetcode.cn/problems/smallest-integer-divisible-by-k
// INLINE  ../../images/map/smallest_integer_divisible_by_k.jpeg
#include <headers.hpp>

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0)
      return -1;
    int r = 0;
    for (int i = 1; i <= k; ++i) {
      r = (r * 10 + 1) % k;
      if (r == 0)
        return i;
    }
    return -1;
  }
};