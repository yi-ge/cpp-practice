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
        if (grid[x][y] == 'S') { // 找到玩家的初始位置
          sx = x;
          sy = y;
        } else if (grid[x][y] == 'B') { // 找到箱子的初始位置
          bx = x;
          by = y;
        }
      }
    }

    auto ok = [&](int x, int y) -> bool { // 判断一个位置是否合法
      return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    };
    vector<int> d = {0, -1, 0, 1, 0}; // 用于计算四个方向的偏移量

    vector<vector<int>> dp(m * n, vector<int>(m * n, INT_MAX)); // dp 数组，记录每个状态的最小推动次数
    queue<pair<int, int>> q;
    dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
    q.push({sx * n + sy, bx * n + by});
    while (!q.empty()) { // BFS 处理所有状态
      queue<pair<int, int>> q1;
      while (!q.empty()) {
        auto [s1, b1] = q.front();
        q.pop();
        int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
        if (grid[bx1][by1] == 'T') { // 箱子已被推到目标处，直接返回最小推动次数
          return dp[s1][b1];
        }
        for (int i = 0; i < 4; i++) { // 玩家向四个方向移动到另一个状态
          int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2 * n + sy2;
          if (!ok(sx2, sy2)) { // 玩家位置不合法，跳过
            continue;
          }
          if (bx1 == sx2 && by1 == sy2) { // 玩家推动箱子
            int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2 * n + by2;
            if (!ok(bx2, by2) || dp[s2][b2] <= dp[s1][b1] + 1) { // 箱子位置不合法 或 状态已访问，跳过
              continue;
            }
            dp[s2][b2] = dp[s1][b1] + 1; // 更新最小推动次数
            q1.push({s2, b2});
          } else { // 玩家不推动箱子
            if (dp[s2][b1] <= dp[s1][b1]) { // 状态已访问，跳过
              continue;
            }
            dp[s2][b1] = dp[s1][b1]; // 更新最小推动次数
            q.push({s2, b1});
          }
        }
      }
      q.swap(q1); // 处理下一层状态
    }
    return -1; // 无法推动箱子到目标处，返回 -1
  }
};