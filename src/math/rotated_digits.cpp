// 旋转数字
// https://leetcode.cn/problems/rotated-digits
// INLINE  ../../images/math/rotated_digits.jpeg
#include <headers.hpp>

class Solution {
public:
  int rotatedDigits(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      string num = to_string(i);
      bool valid = true, diff = false;
      for (char ch : num) {
        if (check[ch - '0'] == -1) {
          valid = false;
        } else if (check[ch - '0'] == 1) {
          diff = true;
        }
      }
      if (valid && diff) {
        ++ans;
      }
    }
    return ans;
  }

private:
  static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
  // 数中没有出现 3 4 7
  // 数中至少出现一次 2 或 5 或 6 或 9
};