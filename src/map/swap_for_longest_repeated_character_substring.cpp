// 单字符重复子串的最大长度
// https://leetcode.cn/problems/swap-for-longest-repeated-character-substring
// INLINE  ../../images/map/swap_for_longest_repeated_character_substring.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxRepOpt1(string text) {
    int l = 0, n = text.size(), ans = 0;
    while (l < n) {
      int r = l + 1;
      while (r < n && text[r] == text[l])
        r++; // 找到第一个和text[l]不同的位置
      if (r == n)
        return max(ans, r - l + (text.substr(0, l).find(text[l]) != string::npos)); // 处理在字符串末尾
      int l_ = r;
      r++;
      while (r < n && text[r] == text[l])
        r++; // 找到第二个和text[l]不同的位置
      if (r - l > ans)
        ans = max(ans, r - l - ((text.substr(0, l).find(text[l]) == string::npos) && (text.substr(r, n - r).find(text[l]) == string::npos))); // 处理
      l = l_;
    }
    return ans;
  }
};