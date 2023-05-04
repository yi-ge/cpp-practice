// 处理用时最长的那个任务的员工
// https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task
// INLINE  ../../images/array/the_employee_that_worked_on_the_longest_task.jpeg
#include <headers.hpp>

class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int ans = logs[0][0];
    int max = logs[0][1];
    for (int i = 1; i < logs.size(); ++i) {
      int idx = logs[i][0];
      int cost = logs[i][1] - logs[i - 1][1];
      if (cost > max || (cost == max && idx < ans)) {
        ans = idx;
        max = cost;
      }
    }
    return ans;
  }
};
