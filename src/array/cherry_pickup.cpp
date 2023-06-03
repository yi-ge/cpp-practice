// 摘樱桃
// https://leetcode.cn/problems/cherry-pickup
// INLINE  ../../images/array/cherry_pickup.jpeg
//
// 解题思路
// 核心在于：把一个人来回走等价成两个人从起点走到终点。
// 即，本题求两个人从起点走到终点摘到的樱桃个数之和的最大值。
// 详细思路参阅代码注释及官方题解：https://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/
// TODO: 重做该题

#include <headers.hpp>
#include <limits.h>

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size(); // n 同题目网格 "N"
    vector<vector<int>> f(
        n, vector<int>(n, INT_MIN)); // f 表示俩人摘到的樱桃个数之和的最大值
    f[0][0] = grid[0][0];
    for (int k = 1; k < n * 2 - 1; ++k) { // k为两人步数之和，x为向右走的步数，y为向下走的步数。
                                          // x_1+y_1 = x_2+y_2 = k
      for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) { // 枚举第一个人走的位置
        for (int x2 = min(k, n - 1); x2 >= x1; --x2) { // 枚举第二个人走的位置
          int y1 = k - x1, y2 = k - x2; // 根据步数和位置，计算出两个人的纵坐标
          if (grid[x1][y1] == -1 || grid[x2][y2] == -1) { // 如果当前格子是障碍物，则无法通过
            f[x1][x2] = INT_MIN; // 将当前状态设为无穷小，表示无法达到
            continue;
          }
          int res = f[x1][x2]; // 初始化最大值为当前状态
          if (x1) { // 第一个人可以向下走
            res = max(res, f[x1 - 1][x2]); // 更新状态，加上向下走的樱桃数
          }
          if (x2) { // 第二个人可以向下走
            res = max(res, f[x1][x2 - 1]); // 更新状态，加上向下走的樱桃数
          }
          if (x1 && x2) { // 两个人都可以向下走
            res = max(res, f[x1 - 1][x2 - 1]); // 更新状态，加上向下走的樱桃数
          }
          res += grid[x1][y1]; // 加上当前格子的樱桃数
          if (x2 != x1) { // 避免重复摘同一个樱桃
            res += grid[x2][y2]; // 加上第二个人当前格子的樱桃数
          }
          f[x1][x2] = res; // 更新当前状态
        }
      }
    }
    return max(f.back().back(), 0); // 返回俩人摘到的樱桃个数之和的最大值，注意要取0和最大值的较大值
  }
};