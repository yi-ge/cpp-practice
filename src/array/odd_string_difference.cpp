// 差值数组不同的字符串
// https://leetcode.cn/problems/odd-string-difference/
// INLINE  ../../images/array/odd_string_difference.jpeg
// 遍历。这里用官方题解测试覆盖率程序是否能正常工作。
#include <headers.hpp>

class Solution {
public:
  vector<int> get(string &word) {
    vector<int> diff(word.size() - 1);
    for (int i = 0; i + 1 < word.size(); i++) {
      diff[i] = word[i + 1] - word[i];
    }
    return diff;
  }

  string oddString(vector<string> &words) {
    auto diff0 = get(words[0]);
    auto diff1 = get(words[1]);
    if (diff0 == diff1) {
      for (int i = 2; i < words.size(); i++) {
        if (diff0 != get(words[i])) {
          return words[i];
        }
      }
    }
    return diff0 == get(words[2]) ? words[1] : words[0];
  }
};