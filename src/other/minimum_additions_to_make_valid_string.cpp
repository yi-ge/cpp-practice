// 构造有效字符串的最少插入数
// https://leetcode.cn/problems/minimum-additions-to-make-valid-string
// INLINE  ../../images/other/minimum_additions_to_make_valid_string.jpeg

#include <headers.hpp>

class Solution {
public:
  int addMinimum(string word) {
    int n = word.size(), cnt = 1;
    for (int i = 1; i < n; i++) {
      if (word[i] <= word[i - 1]) {
        cnt++;
      }
    }
    return cnt * 3 - n;
  }
};