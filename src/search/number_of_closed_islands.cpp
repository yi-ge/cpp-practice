// 统计封闭岛屿的数目
// https://leetcode.cn/problems/number-of-closed-islands
// INLINE  ../../images/search/number_of_closed_islands.jpeg

#include <headers.hpp>

class Solution {
public:
  int closedIsland(vector<vector<int>> &grid) {
    int ans = 0;

    int n = grid[0].size();
    int m = grid.size();

    // 定义函数 dfs 用于检查从 (x,y) 是否可以到达边界
    function<bool(int, int)> dfs = [&](int x, int y) -> bool {
      // 如果 (x,y) 超出网格边界，说明可以到达边界
      if (x < 0 || y < 0 || x >= m || y >= n) {
        return false;
      }
      // 如果 (x,y) 不是陆地，说明可以到达边界
      if (grid[x][y] != 0) {
        return true;
      }
      // 标记 (x,y) 为已访问
      grid[x][y] = -1;
      // 检查从 (x,y) 是否可以到达边界
      bool ret1 = dfs(x - 1, y);
      bool ret2 = dfs(x + 1, y);
      bool ret3 = dfs(x, y - 1);
      bool ret4 = dfs(x, y + 1);
      // 如果从 (x,y) 可以到达边界，说明不是封闭岛屿
      return ret1 && ret2 && ret3 && ret4;
    };

    // 检查每个网格，找到封闭岛屿
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 如果 (i,j) 是陆地，检查从 (i,j) 是否可以到达边界
        if (grid[i][j] == 0 && dfs(i, j)) {
          ans++;
        }
      }
    }
    return ans;
  }
};