// 子串能表示从 1 到 N 数字的二进制串
// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n
// INLINE
// ../../images/string/binary_string_with_substrings_representing_1_to_n.jpeg
#include <headers.hpp>

class Solution {
public:
  bool queryString(string s, int n) {
    for (int i = n; i > n / 2; --i) {
      if (s.find(bitset<32>(i).to_string().substr(32 - log2(i))) ==
          string::npos) {
        return false;
      }
    }
    return true;
  }
};