// 最小的必要团队
// https://leetcode.cn/problems/smallest-sufficient-team
// INLINE  ../../images/math/smallest_sufficient_team.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> smallestSufficientTeam(const vector<string> &req_skills,
                                     const vector<vector<string>> &people) {
    int n = req_skills.size(), m = people.size();
    unordered_map<string, int> skill_index;
    for (int i = 0; i < n; ++i) {
      skill_index[req_skills[i]] = i;
    }
    vector<int> dp(1 << n, m), prev_skill(1 << n), prev_people(1 << n);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
      int cur_skill = 0;
      for (const string &skill : people[i]) {
        cur_skill |= 1 << skill_index[skill];
      }
      for (int prev = 0; prev < (1 << n); prev++) {
        int comb = prev | cur_skill;
        if (dp[comb] > dp[prev] + 1) {
          dp[comb] = dp[prev] + 1;
          prev_skill[comb] = prev;
          prev_people[comb] = i;
        }
      }
    }
    vector<int> res;
    int i = (1 << n) - 1;
    res.reserve(dp.back());
    while (i > 0) {
      res.emplace_back(prev_people[i]);
      i = prev_skill[i];
    }
    return res;
  }
};
