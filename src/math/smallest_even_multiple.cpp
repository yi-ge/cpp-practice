// 最小偶倍数
// https://leetcode.cn/problems/smallest-even-multiple
// INLINE  ../../images/math/smallest_even_multiple.jpeg
#include <headers.hpp>

class Solution {
public:
  // 计算最小偶倍数
  int smallestEvenMultiple(int n) {
    // 若n为偶数，则n为最小偶倍数
    if (n % 2 == 0) {
      return n;
    }
    // 若n为奇数，则2n为最小偶倍数
    else {
      return 2 * n;
    }
  }
};