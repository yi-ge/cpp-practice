// 二进制矩阵中的最短路径
// https://leetcode.cn/problems/shortest-path-in-binary-matrix/
// INLINE  ../../images/search/shortest_path_in_binary_matrix.jpeg

#include <headers.hpp>

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] == 1) { // 起点不可达
      return -1;
    }

    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // 初始化距离矩阵
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1; // 起点到起点的距离为1

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      if (x == n - 1 && y == n - 1) { // 到达终点
        return dist[x][y];
      }

      for (int dx = -1; dx <= 1; ++dx) { // 枚举相邻的8个方向
        for (int dy = -1; dy <= 1; ++dy) {
          int nx = x + dx;
          int ny = y + dy;

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) { // 越界
            continue;
          }

          if (grid[nx][ny] == 1 || dist[nx][ny] <= dist[x][y] + 1) { // 障碍物或者已经更新过距离
            continue;
          }

          dist[nx][ny] = dist[x][y] + 1; // 更新距离
          q.push({nx, ny});
        }
      }
    }
    return -1; // 无法到达终点
  }
};