// 数青蛙
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking
// INLINE  ../../images/string/minimum_number_of_frogs_croaking.jpeg
#include <headers.hpp>

class Solution {
public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int c = 0, r = 0, o = 0, a = 0, k = 0;
    int max_frogs = 0;
    for (auto ch : croakOfFrogs) {
      switch (ch) {
      case 'c':
        ++c;
        break;
      case 'r':
        ++r;
        break;
      case 'o':
        ++o;
        break;
      case 'a':
        ++a;
        break;
      case 'k':
        ++k;
        break;
      }
      if (c < r || r < o || o < a || a < k) {
        return -1;
      }
      max_frogs = max(max_frogs, c);
      if (k == 1) {
        --c;
        --r;
        --o;
        --a;
        --k;
      }
    }
    if (c != 0 || r != 0 || o != 0 || a != 0 || k != 0) {
      return -1; // LCOV_EXCL_LINE
    }
    return max_frogs;
  }
};