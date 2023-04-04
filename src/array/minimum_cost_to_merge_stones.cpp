// 合并石头的最低成本
// https://leetcode.cn/problems/minimum-cost-to-merge-stones
// INLINE  ../../images/array/minimum_cost_to_merge_stones.jpeg
// 区间DP + 前缀和
#include <headers.hpp>

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1)) {
      return -1;
    }
    int s[n + 1];
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
      s[i] = s[i - 1] + stones[i - 1];
    }
    int f[n + 1][n + 1][k + 1];
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i) {
      f[i][i][1] = 0;
    }
    for (int l = 2; l <= n; ++l) {
      for (int i = 1; i + l - 1 <= n; ++i) {
        int j = i + l - 1;
        for (int l = 1; l <= k; ++l) {
          for (int h = i; h < j; ++h) {
            f[i][j][l] = min(f[i][j][l], f[i][h][1] + f[h + 1][j][l - 1]);
          }
        }
        f[i][j][1] = f[i][j][k] + s[j] - s[i - 1];
      }
    }
    return f[1][n][1];
  }
};