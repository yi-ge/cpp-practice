// 多边形三角剖分的最低得分
// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon
// INLINE  ../../images/array/minimum_score_triangulation_of_polygon.jpeg
#include <headers.hpp>

class Solution {
public:
  int minScoreTriangulation(vector<int> &values) {
    int n = values.size(); // 点的数量
    vector<vector<int>> dp(n, vector<int>(n, 0)); // dp数组，dp[i][j]表示从第i个点到第j个点的最低得分
    for (int i = n - 1; i >= 0; i--) { // 枚举起点i
      for (int j = i + 2; j < n; j++) { // 枚举终点j
        for (int k = i + 1; k < j; k++) { // 枚举中间的点k
          int temp = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]; // 根据公式计算三角形的得分
          if (dp[i][j] == 0 || temp < dp[i][j]) { // 如果dp[i][j]还没有被赋值或者当前计算出来的得分更低，更新dp[i][j]
            dp[i][j] = temp;
          }
        }
      }
    }
    return dp[0][n - 1]; // 返回从第0个点到第n-1个点的最低得分
  }
};