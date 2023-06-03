// 移动石子直到连续
// https://leetcode.cn/problems/moving-stones-until-consecutive
// INLINE  ../../images/math/moving_stones_until_consecutive.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> res(2); // 存放结果的数组
    vector<int> v = {a, b, c}; // 存放三个石子的数组
    sort(v.begin(), v.end()); // 将三个石子从小到大排序
    a = v[0];
    b = v[1];
    c = v[2];
    if (a + 1 == b && b + 1 == c) { // 如果三个石子已经连续，则不需要移动
      res[0] = 0;
    } else if (a + 1 == b || b + 1 == c || a + 2 == b || b + 2 == c) { // 如果有一个石子可以移到中间，则只需要移动一次
      res[0] = 1;
    } else { // 否则需要移动两次
      res[0] = 2; // LCOV_EXCL_LINE
    }
    res[1] = c - a - 2; // 最多需要移动的距离为石子之间的间隔减去2
    return res; // 返回结果数组
  }
};