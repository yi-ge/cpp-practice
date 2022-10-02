// 赎金信
// https://leetcode.cn/problems/ransom-note/
// INLINE  ../../images/map/ransom_note.jpeg
#include <headers.hpp>

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size())
      return false;

    vector<int> count(26); // 26个英文字母计数
    for (auto &c : magazine) {
      ++count[c - 'a'];
    }

    for (auto &c : ransomNote) {
      --count[c - 'a'];
      if (count[c - 'a'] < 0)
        return false;
    }

    return true;
  }
};