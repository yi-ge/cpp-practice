// 找出叠涂元素
// https://leetcode.cn/problems/first-completely-painted-row-or-column
// INLINE  ../../images/array/first_completely_painted_row_or_column.jpeg

#include <headers.hpp>

class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    unordered_map<int, pair<int, int>> mp;
    vector<int> rowCnt(n, 0);
    vector<int> colCnt(m, 0);
    int completeIndex = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mp[mat[i][j]] = {i, j};
      }
    }
    for (int i = 0; i < arr.size(); ++i) {
      auto &v = mp[arr[i]];
      ++rowCnt[v.first];
      if (rowCnt[v.first] == m) {
        completeIndex = i;
        break;
      }
      ++colCnt[v.second];
      if (colCnt[v.second] == n) {
        completeIndex = i;
        break;
      }
    }
    return completeIndex;
  }
};