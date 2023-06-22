// 水域大小
// https://leetcode.cn/problems/pond-sizes-lcci
// INLINE  ../../images/search/pond_sizes_lcci.jpeg

#include <headers.hpp>

class Solution {
public:
  vector<int> pondSizes(vector<vector<int>> &land) {
    int m = land.size(), n = land[0].size();
    // List of directions to traverse (up, down, left, right, diagonals)
    vector<pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    function<int(int, int)> dfs = [&](int x, int y) -> int {
      if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
        return 0;
      }
      land[x][y] = -1; // Mark as visited
      int res = 1;
      for (const auto &dir : directions) {
        res += dfs(x + dir.first, y + dir.second);
      }
      return res;
    };

    vector<int> res;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (land[i][j] == 0) {
          res.push_back(dfs(i, j));
        }
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};