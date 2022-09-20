// 字符串相加
// https://leetcode.cn/problems/add-strings/
// INLINE  ../../images/math/add_strings.jpeg
// 解题思路： 模拟数学计算过程。
#include <headers.hpp>

class Solution {
public:
  string addStrings(string num1, string num2) {
    int a = num1.size() - 1, b = num2.size() - 1;
    bool carry = false; // 是否进位
    string res = "";
    while (a >= 0 || b >= 0 || carry) {
      int x = a >= 0 ? num1[a] - '0' : 0;
      int y = b >= 0 ? num2[b] - '0' : 0;
      int ans = x + y + (carry ? 1 : 0);
      res.insert(0, to_string(ans % 10));
      a--;
      b--;
      carry = ans / 10 != 0;
    }

    return res;
  }
};