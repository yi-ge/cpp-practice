// 自由之路
// https://leetcode.cn/problems/freedom-trail
// INLINE  ../../images/search/freedom_trail.jpeg

#include <headers.hpp>

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    array<vector<int>, 26> idx_list;
    int n = ring.size(), m = key.size(), pc = ring.front() - 'a';
    for (int i = 0; i < n; ++i)
      idx_list[ring[i] - 'a'].push_back(i);
    vector<int> dp(n, 0x3f3f3f3f), pre(n, 0x3f3f3f3f);
    pre[0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int idx : idx_list[key[i] - 'a'])
        for (int pi : idx_list[pc])
          dp[idx] =
              min(dp[idx], pre[pi] + min(abs(pi - idx), n - abs(pi - idx)));
      pre = std::move(dp);
      dp = vector(n, 0x3f3f3f3f);
      pc = key[i] - 'a';
    }
    return *min_element(pre.begin(), pre.end()) + key.size();
  }
};