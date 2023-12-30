// 一周中的第几天
// https://leetcode.cn/problems/day-of-the-week
// INLINE  ../../images/math/day_of_the_week.jpeg

#include <headers.hpp>

class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    // 距离 1970 年 12 月 31 日有几天，再加上 3 后对 7 求余
    vector<string> week = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                           "Friday", "Saturday", "Sunday"};
    vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int days = 365 * (year - 1971) + (year - 1969) / 4;
    for (int i = 0; i < month - 1; ++i) {
      days += monthDays[i];
    }
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2) {
      days += day + 1;
    }
    days += day;
    return week[(days + 3) % 7];
  }
};