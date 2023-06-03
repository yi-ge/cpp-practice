// 工作计划的最低难度
// https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule
// INLINE  ../../images/array/minimum_difficulty_of_a_job_schedule.jpeg
#include <headers.hpp>

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) { // 特判：任务数小于天数，无法分配
      return -1;
    }
    vector<int> dp(n);
    int max = 0;
    for (int j = 0; j < n; ++j) { // 初始化 dp 数组，记录每个任务及其前面的任务中的最大难度
      max = std::max(max, jobDifficulty[j]);
      dp[j] = max;
    }
    for (int i = 1; i < d; ++i) { // 依次处理每一天
      stack<pair<int, int>> st; // 维护一个单调递增栈，用于找到当前任务之前的最小难度
      vector<int> ndp(n); // 记录每一天的 dp 值
      for (int j = i; j < n; ++j) { // 处理第 i 天的任务
        int mi = dp[j - 1]; // 初始化最小难度为前一个任务的最大难度
        while (!st.empty() && jobDifficulty[st.top().first] < jobDifficulty[j]) { // 更新最小难度
          mi = std::min(mi, st.top().second);
          st.pop();
        }
        if (st.empty()) { // 如果栈为空，说明当前任务之前的所有任务都可以在前一天完成，所以当前任务的难度为前一天的最大难度加上当前任务的难度
          ndp[j] = mi + jobDifficulty[j];
        } else { // 否则，当前任务之前的一部分任务需要在当前天完成，所以当前任务的难度为这部分任务的最小难度加上当前任务的难度
          ndp[j] = std::min(ndp[st.top().first], mi + jobDifficulty[j]);
        }
        st.emplace(j, mi); // 将当前任务入栈
      }
      swap(dp, ndp); // 更新 dp 数组
    }
    return dp[n - 1]; // 返回最后一天的 dp 值
  }
};