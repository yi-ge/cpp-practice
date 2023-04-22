// 第一个出现两次的字母
// https://leetcode.cn/problems/first-letter-to-appear-twice
// INLINE  ../../images/map/first_letter_to_appear_twice.jpeg
#include <headers.hpp>

class Solution {
public:
  char repeatedCharacter(string s) {
    unordered_set<char> seen;
    for (char ch : s) {
      if (seen.count(ch)) {
        return ch;
      }
      seen.insert(ch);
    }

    return ' '; // 按照题意不会出现该值
  }
};