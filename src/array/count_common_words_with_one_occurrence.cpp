// 统计出现过一次的公共字符串
// https://leetcode.cn/problems/count-common-words-with-one-occurrence
// INLINE  ../../images/array/count_common_words_with_one_occurrence.jpeg

#include <headers.hpp>

class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> map1, map2;
    for (const string &w : words1) {
      ++map1[w];
    }
    for (const string &w : words2) {
      ++map2[w];
    }

    int res = 0;
    for (const auto &[w, cnt1] : map1) {
      if (cnt1 == 1 && map2[w] == 1) {
        ++res;
      }
    }
    return res;
  }
};