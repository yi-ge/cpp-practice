// T 秒后青蛙的位置
// https://leetcode.cn/problems/frog-position-after-t-seconds/
// INLINE  ../../images/graphs/frog_position_after_t_seconds.jpeg
// 参考官方题解
#include <headers.hpp>

class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < edges.size(); ++i) {
      G[edges[i][0]].push_back(edges[i][1]);
      G[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(n + 1, false);
    return dfs(G, visited, 1, t, target);
  }

  double dfs(vector<vector<int>> &G, vector<bool> &visited, int i, int t,
             int target) {
    int nxt = i == 1 ? G[i].size() : G[i].size() - 1;
    if (t == 0 || nxt == 0) {
      return i == target ? 1.0 : 0.0;
    }
    visited[i] = true;
    double ans = 0.0;
    for (int j : G[i]) {
      if (!visited[j]) {
        ans += dfs(G, visited, j, t - 1, target);
      }
    }
    return ans / nxt;
  }
};