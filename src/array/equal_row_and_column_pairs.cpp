// 相等行列对
// https://leetcode.cn/problems/equal-row-and-column-pairs
// INLINE  ../../images/array/equal_row_and_column_pairs.jpeg
#include <headers.hpp>

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    // 记录每行出现的次数
    int n = grid.size();
    map<vector<int>, int> countMap;
    for (auto row : grid) {
      countMap[row]++;
    }

    // 对于每一列，检查是否有重复的行
    int res = 0;
    for (int j = 0; j < n; j++) {
      vector<int> arr;
      for (int i = 0; i < n; i++) {
        arr.emplace_back(grid[i][j]);
      }
      // 如果有重复的行，将对数累加
      if (countMap.find(arr) != countMap.end()) {
        res += countMap[arr];
      }
    }
    return res;
  }
};