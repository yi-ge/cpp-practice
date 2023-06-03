// 有序矩阵中的第 k 个最小数组和
// https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
// INLINE
// ../../images/array/find_the_kth_smallest_sum_of_a_matrix_with_sorted_rows.jpeg
#include <headers.hpp>

class Solution {
public:
  int kthSmallest(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<int> ans = mat[0];     // 初始化ans为第一行
    for (int i = 1; i < m; ++i) { // 从第二行开始遍历
      vector<int> tmp;
      for (int j = 0; j < n; ++j) { // 遍历当前行的每个元素
        for (int x : ans) {         // 遍历上一行的每个元素
          tmp.push_back(
              x +
              mat[i][j]); // 计算上一行元素与当前行元素之和，并将结果加入tmp中
        }
      }
      sort(tmp.begin(), tmp.end()); // 对tmp中的元素进行排序
      ans = vector<int>(tmp.begin(),
                        tmp.begin() +
                            min(k, (int)tmp.size())); // 将前k小的元素赋值给ans
    }
    return ans[k - 1]; // 返回第k小的元素
  }
};