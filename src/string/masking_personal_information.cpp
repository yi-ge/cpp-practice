// 隐藏个人信息
// https://leetcode.cn/problems/masking-personal-information
// INLINE  ../../images/string/masking_personal_information.jpeg
#include <headers.hpp>

class Solution {
public:
  string maskPII(string s) {
    vector<string> country = {"", "+*-", "+**-", "+***-"}; // 国家码对应的号码格式
    auto at = s.find('@'); // 找到邮箱地址中 @ 的位置
    if (at != string::npos) { // 如果找到了 @，说明输入的是邮箱地址
      auto lower_s = s;
      transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower); // 将邮箱地址中的字母转换成小写
      return lower_s.substr(0, 1) + "*****" + lower_s.substr(at - 1); // 返回加密后的邮箱地址
    }
    auto digit_s = string{}; // 存放字符串中的数字
    for (auto c : s) { // 遍历字符串中的每个字符
      if (isdigit(c)) { // 如果是数字
        digit_s += c; // 将数字添加到 digit_s 中
      }
    }
    return country[digit_s.size() - 10] + "***-***-" + // 返回加密后的电话号码
           digit_s.substr(digit_s.size() - 4); // 取出后四位数字
  }
};