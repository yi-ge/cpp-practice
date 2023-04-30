// 通知所有员工所需的时间
// https://leetcode.cn/problems/time-needed-to-inform-all-employees
// INLINE  ../../images/tree/time_needed_to_inform_all_employees.jpeg
#include <headers.hpp>

class Solution {
public:
  int dfs(vector<vector<int>> &tree, vector<int> &informTime, int root) {
    int maxTime = 0;
    for (int &sub : tree[root]) {
      maxTime = max(maxTime, dfs(tree, informTime, sub));
    }
    return maxTime + informTime[root];
  }
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; ++i) {
      if (manager[i] != -1) {
        tree[manager[i]].push_back(i);
      }
    }
    return dfs(tree, informTime, headID);
  }
};