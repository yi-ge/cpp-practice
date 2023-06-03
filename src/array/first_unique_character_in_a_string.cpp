// 字符串中的第一个唯一字符
// https://leetcode-cn.com/problems/first-unique-character-in-a-string/
// INLINE  ../../images/array/first_unique_character_in_a_string.jpeg
#include <headers.hpp>

class Solution {
public:
  int firstUniqChar(string s) {
    // 统计每个字符出现的频率
    unordered_map<int, int> frequency;
    for (auto ch : s) {
      frequency[ch]++;
    }

    // 遍历字符串，找到第一个出现频率为1的字符
    for (int i = 0; i < s.length(); i++) {
      if (frequency[s[i]] == 1) {
        // 返回该字符的索引
        return i;
      }
    }

    // 如果没有找到出现频率为1的字符，返回-1
    return -1;
  }
};