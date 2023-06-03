// 统计字典序元音字符串的数目
// https://leetcode.cn/problems/count-sorted-vowel-strings
// INLINE  ../../images/math/count_sorted_vowel_strings.jpeg
#include <headers.hpp>

class Solution {
public:
  int countVowelStrings(int n) {
    vector<int> dp(5, 1); // 初始化动态规划数组，长度为5，每个元素初始值为1
    for (int i = 1; i < n; i++) { // 从第二个位置开始遍历，一直到第n个位置
      for (int j = 1; j < 5; j++) { // 遍历当前位置可以使用的元音字母，从第一个元音字母a开始，到第五个元音字母u结束
        dp[j] += dp[j - 1]; // 当前位置元音字母为j时，它的方案数等于前一个位置元音字母为j的方案数加上前一个位置元音字母为j-1的方案数
      }
    }
    return accumulate(dp.begin(), dp.end(), 0); // 将所有元素相加，得到总方案数
  }
};