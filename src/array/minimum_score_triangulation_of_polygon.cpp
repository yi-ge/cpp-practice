// 多边形三角剖分的最低得分
// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon
// INLINE  ../../images/array/minimum_score_triangulation_of_polygon.jpeg
#include <headers.hpp>

class Solution {
public:
  int minScoreTriangulation(vector<int> &values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 2; j < n; j++) {
        for (int k = i + 1; k < j; k++) {
          int temp = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];
          if (dp[i][j] == 0 || temp < dp[i][j]) {
            dp[i][j] = temp;
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
