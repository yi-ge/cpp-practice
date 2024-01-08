// 回旋镖的数量
// https://leetcode.cn/problems/number-of-boomerangs
// INLINE  ../../images/array/number_of_boomerangs.jpeg

#include <headers.hpp>

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int res = 0;
    for (auto &p : points) {
      unordered_map<int, int> cnt;
      for (auto &q : points) {
        int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
        ++cnt[dis];
      }
      for (auto &[_, m] : cnt) {
        res += m * (m - 1);
      }
    }
    return res;
  }
};