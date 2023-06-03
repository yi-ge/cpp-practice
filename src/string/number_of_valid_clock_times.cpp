// 有效时间的数目
// https://leetcode.cn/problems/number-of-valid-clock-times
// INLINE  ../../images/string/number_of_valid_clock_times.jpeg
#include <headers.hpp>

class Solution {
public:
  int countTime(string time) {
    // 定义一个lambda函数，用来计算时间中某个位置可能出现的数字的数量
    auto f = [](string s, int m) {
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        // 判断当前位置是否为'?'或者与i/10相等
        bool a = s[0] == '?' || s[0] - '0' == i / 10;
        // 判断当前位置是否为'?'或者与i%10相等
        bool b = s[1] == '?' || s[1] - '0' == i % 10;
        // 如果两个位置都满足条件，计数器加1
        cnt += a && b;
      }
      return cnt; // 返回可能出现的数字数量
    };
    // 计算小时和分钟部分可能出现的数字数量并相乘得到结果
    return f(time.substr(0, 2), 24) * f(time.substr(3, 2), 60);
  }
};