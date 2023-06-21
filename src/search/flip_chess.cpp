// 黑白翻转棋
// https://leetcode.cn/problems/fHi6rV
// 参考：https://leetcode.cn/problems/fHi6rV/solutions/2314858/hei-bai-fan-zhuan-qi-by-leetcode-solutio-1gl9/comments/2047527

#include <headers.hpp>

class Solution {
public:
  int flipChess(vector<string> &chessboard) {
    int m = chessboard.size(), n = chessboard[0].size();
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    int res = 0, cnt;
    vector<string> g; // 复制初始棋盘
    auto bfs = [&](int x0, int y0) {
      queue<pair<int, int>> q; // 保存需要执行操作的位置, 可以是其他容器
      q.emplace(x0, y0);
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
          int find = 0;
          for (int nx = x + dx[k], ny = y + dy[k];
               nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] != '.';
               nx += dx[k], ny += dy[k])
            if (g[nx][ny] == 'X') {
              find = 1;
              break;
            }
          if (find) { // 当前方向存在被包围的白棋
            for (int nx = x + dx[k], ny = y + dy[k];
                 nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] != '.';
                 nx += dx[k], ny += dy[k])
              if (g[nx][ny] != 'X') {
                g[nx][ny] = 'X';
                cnt++; // 更新当前下棋位置可以翻转的白棋数
                q.emplace(nx, ny);
              } else
                break;
          }
        }
      }
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (chessboard[i][j] == '.') { // 枚举可以下棋的位置
          g = chessboard;
          g[i][j] = 'X';
          cnt = 0;
          bfs(i, j);
          res = max(res, cnt);
        }
    return res;
  }
};