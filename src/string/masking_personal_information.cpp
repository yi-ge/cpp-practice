// 隐藏个人信息
// https://leetcode.cn/problems/masking-personal-information
// INLINE  ../../images/string/masking_personal_information.jpeg
#include <headers.hpp>

class Solution {
public:
  string maskPII(string s) {
    vector<string> country = {"", "+*-", "+**-", "+***-"};
    auto at = s.find('@');
    if (at != string::npos) {
      auto lower_s = s;
      transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
      return lower_s.substr(0, 1) + "*****" + lower_s.substr(at - 1);
    }
    auto digit_s = string{};
    for (auto c : s) {
      if (isdigit(c)) {
        digit_s += c;
      }
    }
    return country[digit_s.size() - 10] + "***-***-" +
           digit_s.substr(digit_s.size() - 4);
  }
};
