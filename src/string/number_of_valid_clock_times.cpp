// 有效时间的数目
// https://leetcode.cn/problems/number-of-valid-clock-times
// INLINE  ../../images/string/number_of_valid_clock_times.jpeg
#include <headers.hpp>

class Solution {
public:
  int countTime(string time) {
    auto f = [](string s, int m) {
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        bool a = s[0] == '?' || s[0] - '0' == i / 10;
        bool b = s[1] == '?' || s[1] - '0' == i % 10;
        cnt += a && b;
      }
      return cnt;
    };
    return f(time.substr(0, 2), 24) * f(time.substr(3, 2), 60);
  }
};