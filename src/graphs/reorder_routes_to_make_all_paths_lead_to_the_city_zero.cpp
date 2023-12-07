// 重新规划路线
// https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
// INLINE
// ../../images/graphs/reorder_routes_to_make_all_paths_lead_to_the_city_zero.jpeg

#include <headers.hpp>

class Solution {
private:
  void dfs(int node, vector<bool> &visited, int &res,
           vector<vector<pair<int, bool>>> &graph) {
    visited[node] = true;
    for (auto &[next, is_out] : graph[node]) {
      if (!visited[next]) {
        if (is_out) {
          res++;
        }
        dfs(next, visited, res, graph);
      }
    }
  }

public:
  int minReorder(int n, vector<vector<int>> &connections) {
    int res = 0;
    vector<bool> visited(n, false);
    vector<vector<pair<int, bool>>> graph(n);
    for (auto &connection : connections) {
      graph[connection[0]].push_back({connection[1], true});
      graph[connection[1]].push_back({connection[0], false});
    }
    dfs(0, visited, res, graph);
    return res;
  }
};