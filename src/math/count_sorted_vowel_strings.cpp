// 统计字典序元音字符串的数目
// https://leetcode.cn/problems/count-sorted-vowel-strings
// INLINE  ../../images/math/count_sorted_vowel_strings.jpeg
#include <headers.hpp>

class Solution {
public:
  int countVowelStrings(int n) {
    vector<int> dp(5, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < 5; j++) {
        dp[j] += dp[j - 1];
      }
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};