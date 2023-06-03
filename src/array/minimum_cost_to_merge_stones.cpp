// 合并石头的最低成本
// https://leetcode.cn/problems/minimum-cost-to-merge-stones
// INLINE  ../../images/array/minimum_cost_to_merge_stones.jpeg
// 区间DP + 前缀和
#include <headers.hpp>

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1)) { // 如果无法合并成一堆，返回-1
      return -1;
    }
    int s[n + 1]; // 前缀和数组
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
      s[i] = s[i - 1] + stones[i - 1]; // 计算前缀和
    }
    int f[n + 1][n + 1][k + 1]; // DP数组
    memset(f, 0x3f, sizeof(f)); // 初始化为正无穷
    for (int i = 1; i <= n; ++i) { // 初始化长度为1的区间
      f[i][i][1] = 0;
    }
    for (int l = 2; l <= n; ++l) { // 枚举区间长度
      for (int i = 1; i + l - 1 <= n; ++i) { // 枚举区间起点
        int j = i + l - 1; // 区间终点
        for (int l = 1; l <= k; ++l) { // 枚举拆分成几堆
          for (int h = i; h < j; ++h) { // 枚举拆分点
            f[i][j][l] = min(f[i][j][l], f[i][h][1] + f[h + 1][j][l - 1]); // 转移方程
          }
        }
        f[i][j][1] = f[i][j][k] + s[j] - s[i - 1]; // 计算合并成一堆的成本
      }
    }
    return f[1][n][1]; // 返回合并成一堆的最低成本
  }
};