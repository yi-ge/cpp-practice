// 最大化网格幸福感
// https://leetcode.cn/problems/maximize-grid-happiness
// INLINE  ../../images/math/maximize_grid_happiness.jpeg

// 作者：一夜鱼龙舞
// 链接：https://leetcode.cn/problems/maximize-grid-happiness/solutions/2318350/c-ji-yi-hua-sou-suo-by-exciting-7ehmannm-emy9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <headers.hpp>

class Solution {
public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    vector<vector<vector<vector<int>>>> dp(
        26, vector<vector<vector<int>>>(
                7, vector<vector<int>>(7, vector<int>(250, -1))));
    int pow1 = pow(3, n);
    int pow2 = pow(3, n - 1);
    vector<vector<int>> offset = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    function<int(int, int, int, int)> dfs = [&](int cur, int a, int b,
                                                int status) -> int {
      if (cur == m * n) {
        return 0;
      }
      if (dp[cur][a][b][status] != -1) {
        return dp[cur][a][b][status];
      }
      int x = cur / n;
      int y = cur % n;
      int firstState = status / pow2;
      int lastState = status % 3;
      int nextStatus = status * 3 % pow1;
      int ans = dfs(cur + 1, a, b, nextStatus);
      int diff = 0;
      if (a > 0) {
        diff = 120 + offset[1][firstState] + (y > 0) * offset[1][lastState];
        ans = max(ans, diff + dfs(cur + 1, a - 1, b, nextStatus + 1));
      }
      if (b > 0) {
        diff = 40 + offset[2][firstState] + (y > 0) * offset[2][lastState];
        ans = max(ans, diff + dfs(cur + 1, a, b - 1, nextStatus + 2));
      }
      dp[cur][a][b][status] = ans;
      return dp[cur][a][b][status];
    };
    return dfs(0, introvertsCount, extrovertsCount, 0);
  }
};