// 摘樱桃
// https://leetcode.cn/problems/cherry-pickup
// INLINE  ../images/array/cherry_pickup.jpeg
// 解题思路
// 核心在于：把一个人来回走等价成两个人从起点走到终点。
// 即，本题求两个人从起点走到终点摘到的樱桃个数之和的最大值。
// 详细思路参阅代码注释及官方题解：https://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/
// TODO: 重做该题

#include <headers.hpp>

class Solution
{
public:
  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();                               // n 同题目网格 "N"
    vector<vector<int>> f(n, vector<int>(n, INT_MIN)); // f 表示俩人摘到的樱桃个数之和的最大值
    f[0][0] = grid[0][0];
    for (int k = 1; k < n * 2 - 1; ++k) // k为两人步数之和，x为向右走的步数，y为向下走的步数。 x_1+y_1 = x_2+y_2 = k
    {
      for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1)
      {
        for (int x2 = min(k, n - 1); x2 >= x1; --x2)
        {
          int y1 = k - x1, y2 = k - x2;
          if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
          {
            f[x1][x2] = INT_MIN;
            continue;
          }
          int res = f[x1][x2]; // 都往右
          if (x1)
          {
            res = max(res, f[x1 - 1][x2]); // 往下，往右
          }
          if (x2)
          {
            res = max(res, f[x1][x2 - 1]); // 往右，往下
          }
          if (x1 && x2)
          {
            res = max(res, f[x1 - 1][x2 - 1]); // 都往下
          }
          res += grid[x1][y1];
          if (x2 != x1)
          { // 避免重复摘同一个樱桃
            res += grid[x2][y2];
          }
          f[x1][x2] = res;
        }
      }
    }
    return max(f.back().back(), 0);
  }
};