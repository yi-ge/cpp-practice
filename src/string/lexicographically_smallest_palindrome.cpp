// 字典序最小回文串
// https://leetcode.cn/problems/lexicographically-smallest-palindrome
// INLINE  ../../images/string/lexicographically_smallest_palindrome.jpeg

#include <headers.hpp>

class Solution {
public:
  string makeSmallestPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        s[left] = s[right] = min(s[left], s[right]);
      }
      ++left;
      --right;
    }
    return s;
  }
};