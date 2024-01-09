// 字符串中的额外字符
// https://leetcode.cn/problems/extra-characters-in-a-string
// INLINE  ../../images/tree/extra_characters_in_a_string.jpeg

#include <headers.hpp>

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.size();
    vector<int> d(n + 1, INT_MAX);
    unordered_map<string, int> mp;
    for (auto s : dictionary) {
      mp[s]++;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      d[i] = d[i - 1] + 1;
      for (int j = i - 1; j >= 0; j--) {
        if (mp.count(s.substr(j, i - j))) {
          d[i] = min(d[i], d[j]);
        }
      }
    }
    return d[n];
  }
};