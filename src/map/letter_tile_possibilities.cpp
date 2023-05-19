// 活字印刷
// https://leetcode.cn/problems/letter-tile-possibilities
// INLINE  ../../images/map/letter_tile_possibilities.jpeg
#include <headers.hpp>

class Solution {
public:
  int dfs(map<char, int> &m) {
    int sum = 0;
    for (auto &p : m) {
      if (p.second == 0)
        continue;
      sum++;
      p.second--;
      sum += dfs(m);
      p.second++;
    }
    return sum;
  }
  int numTilePossibilities(string tiles) {
    map<char, int> m;
    for (auto c : tiles) {
      m[c]++;
    }
    return dfs(m);
  }
};