// 数青蛙
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking
// INLINE  ../../images/string/minimum_number_of_frogs_croaking.jpeg
#include <headers.hpp>

class Solution {
public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int c = 0, r = 0, o = 0, a = 0, k = 0; // 五个变量分别记录出现了多少个字符
    int max_frogs = 0; // 记录同时存在的最大青蛙数量
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
      if (c < r || r < o || o < a || a < k) { // 如果出现了字符不符合条件，直接返回-1
        return -1;
      }
      max_frogs = max(max_frogs, c); // 更新最大青蛙数量
      if (k == 1) { // 如果已经有一只青蛙叫完了，需要将所有变量减一
        --c;
        --r;
        --o;
        --a;
        --k;
      }
    }
    if (c != 0 || r != 0 || o != 0 || a != 0 || k != 0) { // 如果所有变量不为0，说明有青蛙叫不完整，返回-1
      return -1; // LCOV_EXCL_LINE
    }
    return max_frogs; // 返回最大青蛙数量
  }
};