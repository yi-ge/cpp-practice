// 可被 K 整除的最小整数
// https://leetcode.cn/problems/smallest-integer-divisible-by-k
// INLINE  ../../images/map/smallest_integer_divisible_by_k.jpeg
#include <headers.hpp>

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    // 如果k是偶数或者5的倍数，则无解，返回-1
    if (k % 2 == 0 || k % 5 == 0)
      return -1;
    int r = 0;
    for (int i = 1; i <= k; ++i) {
      // 模拟最小整数的生成过程
      r = (r * 10 + 1) % k;
      // 如果r能够被k整除，则返回当前整数i
      if (r == 0)
        return i;
    }
    // 未找到符合条件的整数，返回-1
    return -1;
  }
};