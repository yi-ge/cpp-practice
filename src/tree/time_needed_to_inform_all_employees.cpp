// 通知所有员工所需的时间
// https://leetcode.cn/problems/time-needed-to-inform-all-employees
// INLINE  ../../images/tree/time_needed_to_inform_all_employees.jpeg
#include <headers.hpp>

class Solution {
public:
  // 深度优先搜索函数，返回从当前节点通知所有下属所需的最长时间
  int dfs(vector<vector<int>> &tree, vector<int> &informTime, int root) {
    int maxTime = 0;
    // 遍历当前节点的所有下属
    for (int &sub : tree[root]) {
      // 递归调用深度优先搜索函数，更新最长时间
      maxTime = max(maxTime, dfs(tree, informTime, sub));
    }
    // 返回当前节点通知下属所需的时间，加上当前节点本身通知所需的时间
    return maxTime + informTime[root];
  }

  // 计算通知所有员工所需的时间
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    // 构建树形结构
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; ++i) {
      if (manager[i] != -1) {
        tree[manager[i]].push_back(i);
      }
    }
    // 调用深度优先搜索函数，计算通知所有员工所需的时间
    return dfs(tree, informTime, headID);
  }
};