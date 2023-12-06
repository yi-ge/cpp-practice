// 最小化旅行的价格总和
// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips
// INLINE  ../../images/graphs/minimize_the_total_price_of_the_trips.jpeg
// 参考官方题解，dfs + dp

#include <headers.hpp>

class Solution {
public:
  bool dfs(int node, int parent, int end, vector<vector<int>> &next,
           vector<int> &count) {
    if (node == end) {
      count[node]++;
      return true;
    }
    for (int child : next[node]) {
      if (child == parent) {
        continue;
      }
      if (dfs(child, node, end, next, count)) {
        count[node]++;
        return true;
      }
    }
    return false;
  }

  pair<int, int> dp(int node, int parent, vector<vector<int>> &next,
                    vector<int> &price, vector<int> &count) {
    pair<int, int> res = {price[node] * count[node],
                          price[node] * count[node] / 2};
    for (int child : next[node]) {
      if (child == parent) {
        continue;
      }
      auto [x, y] = dp(child, node, next, price, count);
      res.first += min(x, y); // node 没有减半，因此可以取子树的两种情况的最小值
      res.second += x; // node 减半，只能取子树没有减半的情况
    }
    return res;
  }

  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    vector<vector<int>> graph(n);
    vector<vector<int>> next(n);
    for (auto &edge : edges) {
      next[edge[0]].push_back(edge[1]);
      next[edge[1]].push_back(edge[0]);
    }

    vector<int> count(n);
    for (auto &trip : trips) {
      dfs(trip[0], -1, trip[1], next, count);
    }

    auto [x, y] = dp(0, -1, next, price, count);
    return min(x, y);
  }
};