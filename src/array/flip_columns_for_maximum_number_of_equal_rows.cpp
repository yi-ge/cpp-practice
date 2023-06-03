// 按列翻转得到最大值等行数
// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows
// INLINE  ../../images/array/flip_columns_for_maximum_number_of_equal_rows.jpeg
#include <headers.hpp>

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size(); // 获取行列数
    vector<int> flip(n); // 定义一个大小为n的vector，用来存储翻转后的列
    int ans = 0; // 初始化答案
    for (int i = 0; i < m; i++) { // 遍历每一行
      int cnt = 0; // 初始化计数器
      for (int j = 0; j < n; j++) { // 遍历每一列
        flip[j] = 1 - matrix[i][j]; // 计算翻转后的列
      }
      for (int k = 0; k < m; k++) { // 再次遍历每一行
        if (matrix[k] == matrix[i] || matrix[k] == flip) { // 如果该行和当前行相同，或者和当前行翻转后相同
          cnt++; // 计数器加1
        }
      }
      ans = max(ans, cnt); // 更新答案
    }
    return ans; // 返回最终答案
  }
};