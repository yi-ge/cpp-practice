// 负二进制转换
// https://leetcode.cn/problems/convert-to-base-2
// INLINE  ../../images/math/convert_to_base_2.jpeg
#include <headers.hpp>

class Solution {
public:
  string baseNeg2(int n) {
    if (n == 0) {
      return "0";
    }
    string result;
    while (n != 0) {
      result = to_string(n & 1) + result;
      n = -(n >> 1);
    }
    return result;
  }
};