// 按字典序排在最后的子串
// https://leetcode.cn/problems/last-substring-in-lexicographical-order
// INLINE  ../../images/string/last_substring_in_lexicographical_order.jpeg
#include <headers.hpp>

class Solution {
public:
  string lastSubstring(string s) {
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while (j < n) {
      int k = 0; // 计算当前i和j指向的字符后面的相等的字符数
      while (j + k < n && s[i + k] == s[j + k]) {
        k++;
      }
      if (j + k < n && s[i + k] < s[j + k]) { // 如果后面的字符比较大，就将i更新为j，j更新为t+k+1
        int t = i;
        i = j;
        j = max(j + 1, t + k + 1);
      } else { // 如果后面的字符比较小，就将j更新为j+k+1
        j = j + k + 1;
      }
    }
    return s.substr(i, n - i); // 返回i到末尾的子串
  }
};