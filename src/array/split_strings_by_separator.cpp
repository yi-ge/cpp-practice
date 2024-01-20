// 按分隔符拆分字符串
// https://leetcode.cn/problems/split-strings-by-separator
// INLINE  ../../images/array/split_strings_by_separator.jpeg

#include <headers.hpp>

class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
    vector<string> result;
    for (auto &word : words) {
      int start = 0;
      int end = 0;
      while (end < word.size()) {
        if (word[end] == separator) {
          if (start != end) {
            result.push_back(word.substr(start, end - start));
          }
          start = end + 1;
        }
        end++;
      }
      if (start != end) {
        result.push_back(word.substr(start, end - start));
      }
    }
    return result;
  }
};