// 按列翻转得到最大值等行数
// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows
// INLINE  ../../images/array/flip_columns_for_maximum_number_of_equal_rows.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> flip(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        flip[j] = 1 - matrix[i][j];
      }
      for (int k = 0; k < m; k++) {
        if (matrix[k] == matrix[i] || matrix[k] == flip) {
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};