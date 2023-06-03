// 赎金信
// https://leetcode.cn/problems/ransom-note/
// INLINE  ../../images/map/ransom_note.jpeg
#include <headers.hpp>

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() >
        magazine.size()) // 如果赎金信的长度大于杂志的长度，则无法构造
      return false;

    vector<int> count(26);     // 初始化26个英文字母的计数数组
    for (auto &c : magazine) { // 遍历杂志中的每一个字符
      ++count[c - 'a'];        // 将该字符的计数器加1
    }

    for (auto &c : ransomNote) { // 遍历赎金信中的每一个字符
      --count[c - 'a'];          // 将该字符的计数器减1
      if (count[c - 'a'] <
          0) // 如果计数器小于0，则说明杂志中没有足够的该字符，无法构造赎金信
        return false;
    }

    return true; // 所有字符均已遍历完，说明可以构造赎金信
  }
};