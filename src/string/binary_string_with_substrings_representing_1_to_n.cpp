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
      std::string binary = std::bitset<32>(n).to_string();
      size_t pos = binary.find('1');
      if (s.find(binary.substr(pos)) == std::string::npos) {
        return false;
      }
      n--;
    }
    return true;
  }
};