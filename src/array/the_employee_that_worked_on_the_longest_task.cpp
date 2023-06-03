// 处理用时最长的那个任务的员工
// https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task
// INLINE  ../../images/array/the_employee_that_worked_on_the_longest_task.jpeg
#include <headers.hpp>

class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int ans = logs[0][0]; // 初始化最努力的员工编号为第一条记录的员工编号
    int max = logs[0][1]; // 初始化最长用时为第一条记录的用时
    for (int i = 1; i < logs.size(); ++i) { // 遍历所有记录
      int idx = logs[i][0]; // 当前记录的员工编号
      int cost = logs[i][1] - logs[i - 1][1]; // 当前记录和上一条记录之间的用时差
      if (cost > max || (cost == max && idx < ans)) { // 如果当前记录的用时比最长用时长，或者用时相等但员工编号更小，则更新最努力的员工编号和最长用时
        ans = idx;
        max = cost;
      }
    }
    return ans; // 返回最努力的员工编号
  }
};