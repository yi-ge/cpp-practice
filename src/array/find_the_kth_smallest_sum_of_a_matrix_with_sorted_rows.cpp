// 有序矩阵中的第 k 个最小数组和
// https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
// INLINE
// ../../images/array/find_the_kth_smallest_sum_of_a_matrix_with_sorted_rows.jpeg
#include <headers.hpp>

class Solution {
public:
  int kthSmallest(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<int> ans = mat[0];
    for (int i = 1; i < m; ++i) {
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        for (int x : ans) {
          tmp.push_back(x + mat[i][j]);
        }
      }
      sort(tmp.begin(), tmp.end());
      ans = vector<int>(tmp.begin(), tmp.begin() + min(k, (int)tmp.size()));
    }
    return ans[k - 1];
  }
};