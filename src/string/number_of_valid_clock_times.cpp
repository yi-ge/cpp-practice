// 有效时间的数目
// https://leetcode.cn/problems/number-of-valid-clock-times
// INLINE  ../../images/string/number_of_valid_clock_times.jpeg
#include <headers.hpp>

class Solution {
public:
  bool isValid(string time, int hour, int minute) {
    int h1 = hour / 10, h2 = hour % 10;
    int m1 = minute / 10, m2 = minute % 10;
    return time[0] == '?' || time[0] - '0' == h1 && time[1] == '?' ||
           time[1] - '0' == h2 && time[3] == '?' ||
           time[3] - '0' == m1 && time[4] == '?' || time[4] - '0' == m2;
  }
  int countTime(string time) {
    int count = 0;
    for (int i = 0; i < 24; ++i) {
      for (int j = 0; j < 60; ++j) {
        if (isValid(time, i, j)) {
          ++count;
        }
      }
    }
    return count;
  }
};