// 重塑矩阵
// https://leetcode.cn/problems/reshape-the-matrix/
// INLINE  ../../images/array/reshape_the_matrix.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c) {
      return mat;
    }

    vector<vector<int>> ans(r, vector<int>(c));
    for (int x = 0; x < m * n; ++x) {
      ans[x / c][x % c] = mat[x / n][x % n];
    }
    return ans;
  }
};