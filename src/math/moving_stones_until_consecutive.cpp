// 移动石子直到连续
// https://leetcode.cn/problems/moving-stones-until-consecutive
// INLINE  ../../images/math/moving_stones_until_consecutive.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> res(2);
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    a = v[0];
    b = v[1];
    c = v[2];
    if (a + 1 == b && b + 1 == c) {
      res[0] = 0;
    } else if (a + 1 == b || b + 1 == c || a + 2 == b || b + 2 == c) {
      res[0] = 1;
    } else {
      res[0] = 2; // LCOV_EXCL_LINE
    }
    res[1] = c - a - 2;
    return res;
  }
};