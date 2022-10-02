// 字符串中的第一个唯一字符
// https://leetcode.cn/problems/first-unique-character-in-a-string/
// INLINE  ../../images/array/first_unique_character_in_a_string.jpeg
#include <headers.hpp>

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<int, int> frequency;
    for (auto ch : s) {
      frequency[ch]++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (frequency[s[i]] == 1) {
        // return s[i];
        return i;
      }
    }

    return -1;
  }
};