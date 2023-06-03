// 子串能表示从 1 到 N 数字的二进制串
// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n
// INLINE
// ../../images/string/binary_string_with_substrings_representing_1_to_n.jpeg
#include <bitset>
#include <headers.hpp>

class Solution {
public:
  bool queryString(string s, int n) {
    while (n > 0) {
      // 将十进制数 n 转换为 32 位二进制数，并转换为字符串形式
      std::string binary = std::bitset<32>(n).to_string();
      // 找到 binary 中第一个 '1' 的位置
      size_t pos = binary.find('1');
      // 在字符串 s 中查找从 pos 位置开始的子串，如果不存在则返回 false
      if (s.find(binary.substr(pos)) == std::string::npos) {
        return false;
      }
      // 继续判断下一个数
      n--;
    }
    // 所有数都符合要求，返回 true
    return true;
  }
};