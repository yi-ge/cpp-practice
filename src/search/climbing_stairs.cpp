// 爬楼梯
// https://leetcode.cn/problems/climbing-stairs
// INLINE  ../../images/search/climbing_stairs.jpeg

#include <headers.hpp>

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; ++i) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};