// 老鼠和奶酪
// https://leetcode.cn/problems/mice-and-cheese
// INLINE  ../../images/sort/mice_and_cheese.jpeg
#include <headers.hpp>

class Solution {
public:
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int totalReward = 0;                        // 总奖励
    int rewardCount = reward1.size();           // 奖励数量
    vector<int> rewardDifferences(rewardCount); // 奖励差异

    for (int i = 0; i < rewardCount; ++i) {
      totalReward += reward2[i];                      // 计算总奖励
      rewardDifferences[i] = reward1[i] - reward2[i]; // 计算奖励差异
    }

    sort(rewardDifferences.rbegin(),
         rewardDifferences.rend()); // 对奖励差异进行排序

    for (int i = 0; i < k; ++i) {
      totalReward += rewardDifferences[i]; // 计算前k个奖励差异的总和
    }

    return totalReward; // 返回总奖励
  }
};