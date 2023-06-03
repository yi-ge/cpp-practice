// 活字印刷
// https://leetcode.cn/problems/letter-tile-possibilities
// INLINE  ../../images/map/letter_tile_possibilities.jpeg
#include <headers.hpp>

class Solution {
public:
  // 深度优先搜索
  int dfs(map<char, int> &m) {
    int sum = 0;
    for (auto &p : m) {
      if (p.second == 0) // 如果字符已经用完了，跳过
        continue;
      sum++;         // 加上当前字符
      p.second--;    // 用掉一个当前字符
      sum += dfs(m); // 递归计算剩下字符的情况
      p.second++;    // 回溯，将当前字符加回来
    }
    return sum;
  }
  int numTilePossibilities(string tiles) {
    map<char, int> m;
    for (auto c : tiles) {
      m[c]++; // 统计每个字符出现的次数
    }
    return dfs(m); // 深度优先搜索
  }
};