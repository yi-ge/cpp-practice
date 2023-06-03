// 统计范围内的元音字符串数
// https://leetcode.cn/problems/count-vowel-strings-in-ranges
// INLINE  ../../images/array/count_vowel_strings_in_ranges.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    // 计算元音字符串的前缀和。
    // 使用前缀和可以避免重复的字符串比较。
    int n = words.size();
    int prefixSums[n + 1]; // 前缀和数组
    memset(prefixSums, 0, sizeof(prefixSums)); // 初始化为0
    for (int i = 0; i < n; i++) { // 遍历字符串数组
      int value = isVowelString(words[i]) ? 1 : 0; // 判断是否为元音字符串
      prefixSums[i + 1] = prefixSums[i] + value; // 计算前缀和
    }

    // 对于每个查询，返回前缀和的差值。
    vector<int> ans(queries.size()); // 用于存储查询结果的数组
    for (int i = 0; i < queries.size(); i++) { // 遍历查询数组
      int start = queries[i][0], end = queries[i][1]; // 获取查询范围
      ans[i] = prefixSums[end + 1] - prefixSums[start]; // 计算查询结果
    }
    return ans; // 返回查询结果数组
  }

  // 检查字符串是否为元音字符串。
  bool isVowelString(const string &word) {
    return isVowelLetter(word[0]) && isVowelLetter(word.back()); // 判断首尾字母是否为元音字母
  }

  // 检查字母是否为元音字母。
  bool isVowelLetter(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; // 判断是否为元音字母
  }
};