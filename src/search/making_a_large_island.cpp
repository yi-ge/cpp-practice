// 最大人工岛
// https://leetcode.cn/problems/making-a-large-island
// INLINE  ../../images/search/making_a_large_island.jpeg
// 解题思路：并查集。学习自：https://leetcode.cn/problems/making-a-large-island/solution/by-lcbin-f4c1/
#include <headers.hpp>

class Solution {
public:
  const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> p(n * n); // 存储每个点的父节点
    vector<int> size(n * n, 1); // 存储每个点所在连通块的大小，初始化为 1
    std::iota(p.begin(), p.end(), 0); // 初始化每个点的父节点为自己

    // 定义并查集的查找函数
    function<int(int)> find;
    find = [&](int x) {
      if (p[x] != x) {
        p[x] = find(p[x]); // 路径压缩
      }
      return p[x];
    };

    int ans = 1; // 记录最大岛屿的面积
    // 第一遍扫描，合并连通块
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) { // 如果是陆地
          for (int k = 0; k < 4; ++k) { // 向四周扩散
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) { // 如果相邻的点是陆地
              int pa = find(x * n + y), pb = find(i * n + j); // 找到两个点所在连通块的根节点
              if (pa == pb) // 如果已经在同一个连通块中，跳过
                continue;
              p[pa] = pb; // 合并两个连通块
              size[pb] += size[pa]; // 更新新的连通块的大小
              ans = max(ans, size[pb]); // 更新最大岛屿的面积
            }
          }
        }
      }
    }

    // 第二遍扫描，枚举每个海洋格子，统计合并后的面积
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!grid[i][j]) { // 如果是海洋
          int t = 1; // 统计合并后的连通块大小，至少为 1
          unordered_set<int> vis; // 存储已统计过的连通块根节点
          for (int k = 0; k < 4; ++k) { // 向四周扩散
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) { // 如果相邻的点是陆地
              int root = find(x * n + y); // 找到相邻点所在连通块的根节点
              if (!vis.count(root)) { // 如果该连通块还没有被统计过
                vis.insert(root); // 标记为已统计
                t += size[root]; // 更新合并后的连通块大小
              }
            }
          }
          ans = max(ans, t); // 更新最大岛屿的面积
        }
      }
    }
    return ans; // 返回最大岛屿的面积
  }
};