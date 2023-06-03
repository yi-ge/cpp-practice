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
    while (a >= 0 || b >= 0 ||
           carry) { // 只要有一个字符串或者有进位，就继续计算
      int x = a >= 0 ? num1[a] - '0' : 0; // 获取 num1 当前位上的数字
      int y = b >= 0 ? num2[b] - '0' : 0; // 获取 num2 当前位上的数字
      int ans =
          x + y + (carry ? 1 : 0); // 计算当前位的和，如果有进位，需要加上 1
      res.insert(
          0,
          to_string(ans % 10)); // 将当前位的和加入结果字符串，注意是从头部插入
      a--;
      b--;
      carry = ans / 10 != 0; // 根据当前位的和判断是否有进位
    }

    return res;
  }
};