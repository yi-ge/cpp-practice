// 重塑矩阵
// https://leetcode.cn/problems/reshape-the-matrix/
// INLINE  ../../images/array/reshape_the_matrix.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size();    // 矩阵的行数
    int n = mat[0].size(); // 矩阵的列数
    if (m * n !=
        r * c) { // 如果需要重塑的新矩阵元素数量不等于原矩阵元素数量，则无法重塑
      return mat; // 返回原矩阵
    }

    vector<vector<int>> ans(
        r, vector<int>(c)); // 新矩阵的初始值为0，行数为r，列数为c
    for (int x = 0; x < m * n; ++x) { // 遍历原矩阵
      ans[x / c][x % c] =
          mat[x / n]
             [x % n]; // 将原矩阵中的元素按照新矩阵的行列顺序重新赋值给新矩阵
    }
    return ans; // 返回重塑后的新矩阵
  }
};