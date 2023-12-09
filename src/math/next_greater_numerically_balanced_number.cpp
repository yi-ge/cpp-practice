// 下一个更大的数值平衡数
// https://leetcode.cn/problems/next-greater-numerically-balanced-number
// INLINE  ../../images/math/next_greater_numerically_balanced_number.jpeg

#include <headers.hpp>

class Solution {
public:
  static bool isBalancedNumber(int x) {
    vector<int> count(10, 0);
    int temp = x;
    while (temp > 0) {
      count[temp % 10]++;
      temp /= 10;
    }
    for (int d = 0; d < 10; d++) {
      if (count[d] > 0 && count[d] != d) {
        return false;
      }
    }
    return true;
  }

  static int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1224444; i++) {
      if (isBalancedNumber(i)) {
        return i;
      }
    }
    return -1;
  }
};