// 最长字符串链
// https://leetcode.cn/problems/longest-string-chain
// INLINE  ../../images/array/longest_string_chain.jpeg
#include <headers.hpp>

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    // 1. 排序
    sort(words.begin(), words.end(),
         [](const string &a, const string &b) { return a.size() < b.size(); });
    // 2. 动态规划
    unordered_map<string, int> dp;
    int res = 0;
    for (const string &word : words) {
      int max_len = 0;
      for (int i = 0; i < word.size(); ++i) {
        string prev = word.substr(0, i) + word.substr(i + 1);
        max_len = max(max_len, dp[prev] + 1);
      }
      dp[word] = max_len;
      res = max(res, max_len);
    }
    return res;
  }
};