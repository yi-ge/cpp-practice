// 第一个出现两次的字母
// https://leetcode.cn/problems/first-letter-to-appear-twice
// INLINE  ../../images/map/first_letter_to_appear_twice.jpeg
#include <headers.hpp>

class Solution {
public:
  char repeatedCharacter(string s) {
    unordered_set<char> seen; // 创建一个无序集合，用于存储已经出现过的字符
    for (char ch : s) {     // 遍历字符串
      if (seen.count(ch)) { // 如果该字符已经出现过
        return ch;          // 直接返回该字符
      }
      seen.insert(ch); // 将该字符加入集合中
    }

    return ' '; // 按照题意不会出现该值
  }
};