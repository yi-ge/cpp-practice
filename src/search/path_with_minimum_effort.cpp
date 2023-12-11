// 最小体力消耗路径
// https://leetcode.cn/problems/path-with-minimum-effort
// INLINE  ../../images/search/path_with_minimum_effort.jpeg

#include <headers.hpp>

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<>>
        pq;

    // 方向数组
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 初始化
    pq.push({0, {0, 0}});
    effort[0][0] = 0;

    while (!pq.empty()) {
      auto [currEffort, currPos] = pq.top();
      pq.pop();
      int x = currPos.first, y = currPos.second;

      // 到达终点
      if (x == m - 1 && y == n - 1) {
        return currEffort;
      }

      for (auto &dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        // 检查边界
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          // 计算新的努力值
          int newEffort = max(currEffort, abs(heights[x][y] - heights[nx][ny]));
          // 如果找到更小的努力值
          if (newEffort < effort[nx][ny]) {
            effort[nx][ny] = newEffort;
            pq.push({newEffort, {nx, ny}});
          }
        }
      }
    }

    return 0;
  }
};