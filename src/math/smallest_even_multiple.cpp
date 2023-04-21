// 最小偶倍数
// https://leetcode.cn/problems/smallest-even-multiple
// INLINE  ../../images/math/smallest_even_multiple.jpeg
#include <headers.hpp>

class Solution {
public:
  int smallestEvenMultiple(int n) { return n % 2 == 0 ? n : 2 * n; }
};