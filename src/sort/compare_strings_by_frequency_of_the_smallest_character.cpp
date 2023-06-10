// 比较字符串最小字母出现频次
// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character
// INLINE
// ../../images/sort/compare_strings_by_frequency_of_the_smallest_character.jpeg

#include <headers.hpp>

class Solution {
public:
  // f函数计算字符串中最小字母出现的次数
  int f(string &s) {
    int count = 0;
    char min = 'z';
    for (auto c : s) {
      if (c < min) {
        min = c;
        count = 1;
      } else if (c == min) {
        count++;
      }
    }
    return count;
  }
  vector<int> numSmallerByFrequency(vector<string> &queries,
                                    vector<string> &words) {
    vector<int> result;
    // wordsCount用于存储words中每个字符串的f值
    vector<int> wordsCount;
    for (auto word : words) {
      wordsCount.push_back(f(word));
    }
    // 对wordsCount进行排序，方便查找
    sort(wordsCount.begin(), wordsCount.end());
    for (auto query : queries) {
      int count = f(query);
      // i是wordsCount中第一个大于count的元素的索引
      int i = 0;
      for (; i < wordsCount.size(); i++) {
        if (count < wordsCount[i]) {
          break;
        }
      }
      result.push_back(wordsCount.size() - i);
    }
    return result;
  }
};