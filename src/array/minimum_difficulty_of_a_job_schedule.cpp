// 工作计划的最低难度
// https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule
// INLINE  ../../images/array/minimum_difficulty_of_a_job_schedule.jpeg
#include <headers.hpp>

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) {
      return -1;
    }
    vector<int> dp(n);
    int max = 0;
    for (int j = 0; j < n; ++j) {
      max = std::max(max, jobDifficulty[j]);
      dp[j] = max;
    }
    for (int i = 1; i < d; ++i) {
      stack<pair<int, int>> st;
      vector<int> ndp(n);
      for (int j = i; j < n; ++j) {
        int mi = dp[j - 1];
        while (!st.empty() &&
               jobDifficulty[st.top().first] < jobDifficulty[j]) {
          mi = std::min(mi, st.top().second);
          st.pop();
        }
        if (st.empty()) {
          ndp[j] = mi + jobDifficulty[j];
        } else {
          ndp[j] = std::min(ndp[st.top().first], mi + jobDifficulty[j]);
        }
        st.emplace(j, mi);
      }
      swap(dp, ndp);
    }
    return dp[n - 1];
  }
};