// 强整数
// https://leetcode.cn/problems/powerful-integers
// INLINE  ../../images/map/powerful_integers.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> result;
    int value1 = 1;
    for (int i = 0; i < 21; i++) {
      int value2 = 1;
      for (int j = 0; j < 21; j++) {
        int value = value1 + value2;
        if (value <= bound) {
          result.emplace(value);
        } else {
          break;
        }
        value2 *= y;
      }
      if (value1 > bound) {
        break;
      }
      value1 *= x;
    }
    return vector<int>(result.begin(), result.end());
  }
};