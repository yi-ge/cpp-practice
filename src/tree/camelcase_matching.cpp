// 驼峰式匹配
// https://leetcode.cn/problems/camelcase-matching
// INLINE  ../../images/tree/camelcase_matching.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    int n = queries.size();
    vector<bool> res(n, true);

    for (int i = 0; i < n; ++i) {
      int p = 0;
      for (auto c : queries[i]) {
        if (p < pattern.size() && pattern[p] == c) {
          ++p;
        } else if (isupper(c)) {
          res[i] = false;
          break;
        }
      }
      if (p < pattern.size()) {
        res[i] = false;
      }
    }

    return res;
  }
};