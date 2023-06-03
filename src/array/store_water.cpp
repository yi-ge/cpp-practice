// 蓄水
// https://leetcode.cn/problems/o8SXZn
// 这个题目原文有动画，请直接看原文
#include <headers.hpp>

class Solution {
public:
  // 计算最少需要多少次操作才能将所有桶都装满，返回操作次数
  int storeWater(vector<int> &bucket, vector<int> &vat) {
    // 计算桶中最大容量
    int maxVatCapacity = *max_element(vat.begin(), vat.end());
    // 如果最大容量为0，直接返回0
    if (maxVatCapacity == 0)
      return 0;
    // 初始化最少操作次数为INT_MAX
    int minOperations = INT_MAX;
    // 枚举操作次数
    for (int operations = 1; operations <= maxVatCapacity; ++operations) {
      // 记录当前操作次数所需要的移动次数
      int requiredMoves = 0;
      // 遍历每个桶
      for (int i = 0; i < bucket.size(); ++i) {
        // 计算当前桶需要移动的次数，并累加到总移动次数中
        requiredMoves +=
            max(0, (vat[i] + operations - 1) / operations - bucket[i]);
      }
      // 更新最少操作次数
      minOperations = min(minOperations, requiredMoves + operations);
    }
    // 返回最少操作次数
    return minOperations;
  }
};