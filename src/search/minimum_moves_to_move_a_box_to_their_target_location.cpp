// 推箱子
// https://leetcode.cn/problems/minimum-moves-to-move-a-box-to-their-target-location
// INLINE
// ../../images/search/minimum_moves_to_move_a_box_to_their_target_location.jpeg
// 见官方题解
#include <headers.hpp>

class Solution {
public:
  int minPushBox(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int sx, sy, bx, by; // 玩家、箱子的初始位置
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (grid[x][y] == 'S') {
          sx = x;
          sy = y;
        } else if (grid[x][y] == 'B') {
          bx = x;
          by = y;
        }
      }
    }

    auto ok = [&](int x, int y) -> bool { // 不越界且不在墙上
      return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    };
    vector<int> d = {0, -1, 0, 1, 0};

    vector<vector<int>> dp(m * n, vector<int>(m * n, INT_MAX));
    queue<pair<int, int>> q;
    dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
    q.push({sx * n + sy, bx * n + by});
    while (!q.empty()) {
      queue<pair<int, int>> q1;
      while (!q.empty()) {
        auto [s1, b1] = q.front();
        q.pop();
        int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
        if (grid[bx1][by1] == 'T') { // 箱子已被推到目标处
          return dp[s1][b1];
        }
        for (int i = 0; i < 4; i++) { // 玩家向四个方向移动到另一个状态
          int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2 * n + sy2;
          if (!ok(sx2, sy2)) { // 玩家位置不合法
            continue;
          }
          if (bx1 == sx2 && by1 == sy2) { // 推动箱子
            int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2 * n + by2;
            if (!ok(bx2, by2) ||
                dp[s2][b2] <= dp[s1][b1] + 1) { // 箱子位置不合法 或 状态已访问
              continue;
            }
            dp[s2][b2] = dp[s1][b1] + 1;
            q1.push({s2, b2});
          } else {
            if (dp[s2][b1] <= dp[s1][b1]) { // 状态已访问
              continue;
            }
            dp[s2][b1] = dp[s1][b1];
            q.push({s2, b1});
          }
        }
      }
      q.swap(q1);
    }
    return -1;
  }
};