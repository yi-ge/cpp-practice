// 旋转数字
// https://leetcode.cn/problems/rotated-digits
// INLINE  ../../images/math/rotated_digits.jpeg
#include <headers.hpp>

class Solution {
public:
  int rotatedDigits(int n) {
    int ans = 0;
    // 遍历 1 到 n
    for (int i = 1; i <= n; ++i) {
      string num = to_string(i);
      bool valid = true, diff = false;
      for (char ch : num) {
        // 判断数中是否出现 3、4、7，如果出现，则不是旋转数字
        if (check[ch - '0'] == -1) {
          valid = false;
          // 判断数中是否出现 2、5、6、9，如果出现，则是旋转数字
        } else if (check[ch - '0'] == 1) {
          diff = true;
        }
      }
      // 如果数中既没有出现 3、4、7，又至少出现一次 2、5、6、9，则是旋转数字
      if (valid && diff) {
        ++ans;
      }
    }
    return ans;
  }

private:
  // 数中没有出现 3、4、7
  // 数中至少出现一次 2 或 5 或 6 或 9
  static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};