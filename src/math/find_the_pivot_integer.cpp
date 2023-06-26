// 找出中枢整数
// https://leetcode.cn/problems/find-the-pivot-integer
// INLINE  ../../images/math/find_the_pivot_integer.jpeg

#include <headers.hpp>

class Solution {
public:
  int pivotInteger(int n) {
    int t = (n * n + n) / 2;
    int x = sqrt(t);
    if (x * x == t) {
      return x;
    }
    return -1;
  }
};