// 段式回文
// https://leetcode.cn/problems/longest-chunked-palindrome-decomposition
// INLINE  ../../images/string/longest_chunked_palindrome_decomposition.jpeg
// 参考：https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/solution/duan-shi-hui-wen-by-leetcode-solution-vanl/
#include <headers.hpp>

class Solution {
public:
  // 判断两个位置之间的len长度的子串是否相等
  bool judge(const string &text, int l1, int l2, int len) {
    while (len--) {
      if (text[l1] != text[l2]) {
        return false;
      }
      ++l1;
      ++l2;
    }
    return true;
  }
  int longestDecomposition(string text) {
    int n = text.size();
    int res = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
      int len = 1;
      while (l + len - 1 < r - len + 1) {
        // 判断左右两边的子串是否相等
        if (judge(text, l, r - len + 1, len)) {
          res += 2;
          break;
        }
        ++len;
      }
      // 左右两边的子串无法再拼接，只能单独成为一个段
      if (l + len - 1 >= r - len + 1) {
        ++res;
      }
      l += len;
      r -= len;
    }
    return res;
  }
};