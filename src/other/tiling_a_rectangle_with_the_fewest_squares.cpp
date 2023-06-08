// 铺瓷砖
// https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares
// INLINE  ../../images/other/tiling_a_rectangle_with_the_fewest_squares.jpeg
#include <headers.hpp>

class Solution {
public:
  int tilingRectangle(int n, int m) {
    int ans = n * m;                 // 初始化答案为 n * m
    vector<int> filled(n, 0);        // filled[i] 表示第 i 行的瓷砖状态
    dfs(0, 0, 0, n, m, ans, filled); // 深度优先搜索
    return ans;                      // 返回答案
  }

private:
  void dfs(int i, int j, int t, int n, int m, int &ans, vector<int> &filled) {
    if (j == m) { // 如果 j 超出了 m 的范围
      i++;        // 则 i 加 1
      j = 0;      // j 重置为 0
    }
    if (i == n) {        // 如果 i 超出了 n 的范围
      ans = min(ans, t); // 更新答案
      return;            // 返回
    }
    if (filled[i] >> j & 1) { // 如果第 i 行第 j 列已经被铺瓷砖了
      dfs(i, j + 1, t, n, m, ans, filled); // 则继续搜索下一列
    } else if (t + 1 < ans) { // 如果当前铺瓷砖数量加 1 小于答案
      int r = 0, c = 0, mx = 0;
      for (int k = i; k < n; k++) { // 计算当前行可以铺多少行
        if (filled[k] >> j & 1) {
          break;
        }
        r++;
      }
      for (int k = j; k < m; k++) { // 计算当前列可以铺多少列
        if (filled[i] >> k & 1) {
          break;
        }
        c++;
      }
      mx = min(r, c);                     // 取最小值
      for (int w = 1; w <= mx; w++) {     // 枚举铺瓷砖的大小
        vector<int> old_filled = filled;  // 备份 filled
        for (int x = i; x < i + w; x++) { // 铺瓷砖
          for (int y = j; y < j + w; y++) {
            filled[x] |= 1 << y;
          }
        }
        dfs(i, j + w, t + 1, n, m, ans, filled); // 继续搜索
        filled = old_filled;                     // 恢复 filled
      }
    }
  }
};