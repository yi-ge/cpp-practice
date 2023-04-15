// 不邻接植花
// https://leetcode.cn/problems/flower-planting-with-no-adjacent
// INLINE  ../../images/graphs/flower_planting_with_no_adjacent.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<vector<int>> adj(n);
    for (auto &path : paths) {
      adj[path[0] - 1].emplace_back(path[1] - 1);
      adj[path[1] - 1].emplace_back(path[0] - 1);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      vector<bool> colored(5, false);
      for (auto &vertex : adj[i]) {
        colored[ans[vertex]] = true;
      }
      for (int j = 1; j <= 4; j++) {
        if (colored[j] == 0) {
          ans[i] = j;
          break;
        }
      }
    }
    return ans;
  }
};

// 这个解法无法在LeetCode的测试中通过
// class Solution {
// public:
//   vector<int> gardenNoAdj(int garden_size, vector<vector<int>> &paths) {
//     vector<int> color(garden_size + 1, 0); // 记录每个顶点的颜色,0表示未着色
//     vector<unordered_map<int, bool>> adjacency_list(garden_size +
//                                                     1); // 邻接列表

//     // 建立邻接列表
//     for (auto path : paths) {
//       int v1 = path[0];
//       int v2 = path[1];
//       adjacency_list[v1][v2] = true;
//       adjacency_list[v2][v1] = true;
//     }

//     // 依次给每个顶点着色
//     for (int v = 1; v <= garden_size; ++v) {
//       // 如果该顶点未着色,选择一个与所有邻接顶点颜色不同的颜色着色
//       //
//       如果邻接顶点未着色也不考虑,因为我们的方案确保后续顶点着色不会影响之前的顶点
//       vector<bool> available_colors(5, true);

//       // 检查邻接顶点的颜色,并在available_colors中标记为false
//       for (auto neighbor : adjacency_list[v]) {
//         available_colors[color[neighbor.first] - 1] = false;
//       }

//       // 选择第一个可用颜色
//       for (int c = 1; c <= 4; ++c) {
//         if (available_colors[c - 1]) {
//           color[v] = c;
//           break;
//         }
//       }
//     }

//     return vector<int>(color.begin() + 1, color.end());
//   }
// };