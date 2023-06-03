// 最小的必要团队
// https://leetcode.cn/problems/smallest-sufficient-team
// INLINE  ../../images/math/smallest_sufficient_team.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> smallestSufficientTeam(const vector<string> &req_skills, //req_skills为所需技能的字符串数组
                                     const vector<vector<string>> &people) {//people为人员所拥有技能的二维字符串数组
    int n = req_skills.size(), m = people.size();//n为所需技能数，m为人员数
    unordered_map<string, int> skill_index;//使用哈希表存储技能及其下标
    for (int i = 0; i < n; ++i) {
      skill_index[req_skills[i]] = i;
    }
    vector<int> dp(1 << n, m), prev_skill(1 << n), prev_people(1 << n);//使用二进制状态压缩，dp[i]表示技能集合为i时最少需要的人数，prev_skill[i]表示技能集合为i时的前一个状态，prev_people[i]表示技能集合为i时的最后一次加入团队的人员的下标
    dp[0] = 0;//初始状态，技能集合为空，需要的人数为0
    for (int i = 0; i < m; ++i) {//对于每个人员
      int cur_skill = 0;//初始化技能集合为空
      for (const string &skill : people[i]) {//遍历该人员拥有的技能
        cur_skill |= 1 << skill_index[skill];//将其对应的二进制位设为1
      }
      for (int prev = 0; prev < (1 << n); prev++) {//枚举之前的状态
        int comb = prev | cur_skill;//得到新的技能集合
        if (dp[comb] > dp[prev] + 1) {//如果当前状态的需要人数比之前状态加上当前人员需要的人数更少
          dp[comb] = dp[prev] + 1;//更新dp值
          prev_skill[comb] = prev;//更新前一个状态
          prev_people[comb] = i;//更新最后一次加入团队的人员
        }
      }
    }
    vector<int> res;//存储最小团队的人员下标
    int i = (1 << n) - 1;//最终状态，即所有技能都满足
    res.reserve(dp.back());//预分配空间
    while (i > 0) {//从最终状态往前遍历
      res.emplace_back(prev_people[i]);//将最后一次加入团队的人员下标加入结果
      i = prev_skill[i];//更新状态
    }
    return res;//返回结果
  }
};