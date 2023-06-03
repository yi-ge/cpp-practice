// 不邻接植花
// https://leetcode.cn/problems/flower-planting-with-no-adjacent
// INLINE  ../../images/graphs/flower_planting_with_no_adjacent.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<vector<int>> adj(n);                   // 邻接表
    for (auto &path : paths) {                    // 建图
      adj[path[0] - 1].emplace_back(path[1] - 1); // 无向图，建立两条边
      adj[path[1] - 1].emplace_back(path[0] - 1);
    }
    vector<int> ans(n);               // 存储答案
    for (int i = 0; i < n; i++) {     // 遍历每个节点
      vector<bool> colored(5, false); // 记录与该节点相邻的节点的颜色
      for (auto &vertex : adj[i]) {  // 遍历相邻节点
        colored[ans[vertex]] = true; // 标记已经被染色的颜色
      }
      for (int j = 1; j <= 4; j++) { // 找到一个未被染色的颜色进行染色
        if (colored[j] == 0) {
          ans[i] = j;
          break;
        }
      }
    }
    return ans;
  }
};