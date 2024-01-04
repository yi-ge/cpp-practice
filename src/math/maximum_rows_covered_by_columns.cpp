// 被列覆盖的最多行数
// https://leetcode.cn/problems/maximum-rows-covered-by-columns
// INLINE  ../../images/math/maximum_rows_covered_by_columns.jpeg

#include <headers.hpp>

class Solution {
public:
  int maximumRows(vector<vector<int>> &matrix, int numSelect) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> mask(m, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mask[i] += matrix[i][j] << (n - j - 1);
      }
    }
    int res = 0;
    int cur = 0;
    int limit = (1 << n);
    while ((++cur) < limit) {
      if (__builtin_popcount(cur) != numSelect) {
        continue;
      }
      int t = 0;
      for (int j = 0; j < m; j++) {
        if ((mask[j] & cur) == mask[j]) {
          ++t;
        }
      }
      res = max(res, t);
    }
    return res;
  }
};