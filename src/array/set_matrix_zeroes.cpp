// 矩阵置零
// https://leetcode.cn/problems/set-matrix-zeroes
// INLINE  ../../images/array/set_matrix_zeroes.jpeg
#include <headers.hpp>

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size(); // 矩阵行数
    int n = matrix[0].size(); // 矩阵列数
    int flag_col0 = false; // 标记第一列是否需要置零
    for (int i = 0; i < m; i++) {
      if (!matrix[i][0]) { // 如果第一列有零
        flag_col0 = true; // 则标记
      }
      for (int j = 1; j < n; j++) {
        if (!matrix[i][j]) { // 如果当前元素为零
          matrix[i][0] = matrix[0][j] = 0; // 将对应行和列的首元素置零
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) { // 从下往上遍历
      for (int j = 1; j < n; j++) {
        if (!matrix[i][0] || !matrix[0][j]) { // 如果当前行或列的首元素为零
          matrix[i][j] = 0; // 则将该元素置零
        }
      }
      if (flag_col0) { // 如果第一列需要置零
        matrix[i][0] = 0; // 则将当前行的首元素置零
      }
    }
  }
};