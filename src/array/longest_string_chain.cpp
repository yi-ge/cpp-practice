// 最长字符串链
// https://leetcode.cn/problems/longest-string-chain
// INLINE  ../../images/array/longest_string_chain.jpeg
#include <headers.hpp>

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    // 1. 排序，按照字符串长度从小到大排序
    sort(words.begin(), words.end(),
         [](const string &a, const string &b) { return a.size() < b.size(); });
    // 2. 动态规划
    unordered_map<string, int> dp; // 记录每个字符串的最长链长度
    int res = 0; // 记录最长链的长度
    for (const string &word : words) {
      int max_len = 0;
      // 枚举word删除一个字符后的所有可能，找到最长链长度
      for (int i = 0; i < word.size(); ++i) {
        string prev = word.substr(0, i) + word.substr(i + 1);
        max_len = max(max_len, dp[prev] + 1);
      }
      dp[word] = max_len; // 记录当前字符串的最长链长度
      res = max(res, max_len); // 更新最长链的长度
    }
    return res;
  }
};