// 蓄水
// https://leetcode.cn/problems/o8SXZn
// 这个题目原文有动画，请直接看原文
#include <headers.hpp>

class Solution {
public:
  int storeWater(vector<int> &bucket, vector<int> &vat) {
    int maxVatCapacity = *max_element(vat.begin(), vat.end());
    if (maxVatCapacity == 0)
      return 0;
    int minOperations = INT_MAX;
    for (int operations = 1; operations <= maxVatCapacity; ++operations) {
      int requiredMoves = 0;
      for (int i = 0; i < bucket.size(); ++i) {
        requiredMoves +=
            max(0, (vat[i] + operations - 1) / operations - bucket[i]);
      }
      minOperations = min(minOperations, requiredMoves + operations);
    }
    return minOperations;
  }
};