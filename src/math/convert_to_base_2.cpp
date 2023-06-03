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
    string result; // 存储结果的字符串
    while (n != 0) { // 当 n 不为 0 时循环
      result = to_string(n & 1) + result; // 将 n 的最后一位与字符串相加
      n = -(n >> 1); // 取反并右移一位，相当于除以 -2
    }
    return result; // 返回结果字符串
  }
};