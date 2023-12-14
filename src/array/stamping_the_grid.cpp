// 用邮票贴满网格图
// https://leetcode.cn/problems/stamping-the-grid
// INLINE  ../../images/array/stamping_the_grid.jpeg

#include <headers.hpp>

class Solution {
public:
  bool possibleToStamp(vector<vector<int>> &grid, int stampHeight,
                       int stampWidth) {
    int m = grid.size(), n = grid[0].size();

    // 检查网格是否全由1组成
    bool allOnes = true;
    for (const auto &row : grid) {
      for (int cell : row) {
        if (cell == 0) {
          allOnes = false;
          break;
        }
      }
      if (!allOnes)
        break;
    }
    if (allOnes)
      return true;

    // 如果邮票尺寸大于网格本身，无法放置邮票
    if (stampHeight > m || stampWidth > n) {
      return false;
    }

    vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));

    // 计算前缀和
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i - 1][j] +
                          prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
      }
    }

    // 使用差分数组记录邮票放置情况
    for (int i = 1; i <= m - stampHeight + 1; ++i) {
      for (int j = 1; j <= n - stampWidth + 1; ++j) {
        int x = i + stampHeight - 1, y = j + stampWidth - 1;
        if (prefixSum[x][y] - prefixSum[x][j - 1] - prefixSum[i - 1][y] +
                prefixSum[i - 1][j - 1] ==
            0) {
          diff[i][j]++;
          if (y + 1 <= n)
            diff[i][y + 1]--;
          if (x + 1 <= m)
            diff[x + 1][j]--;
          if (x + 1 <= m && y + 1 <= n)
            diff[x + 1][y + 1]++;
        }
      }
    }

    // 更新差分数组并检查是否每个空白格都至少被一个邮票覆盖
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i > 1)
          diff[i][j] += diff[i - 1][j];
        if (j > 1)
          diff[i][j] += diff[i][j - 1];
        if (i > 1 && j > 1)
          diff[i][j] -= diff[i - 1][j - 1];
        if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
          return false;
        }
      }
    }

    return true;
  }
};