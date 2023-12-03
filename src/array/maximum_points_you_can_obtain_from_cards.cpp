// 可获得的最大点数
// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards
// INLINE  ../../images/array/maximum_points_you_can_obtain_from_cards.jpeg

#include <headers.hpp>

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k;
    int sum = 0;
    for (int i = 0; i < windowSize; ++i) {
      sum += cardPoints[i];
    }
    int minSum = sum;
    for (int i = windowSize; i < n; ++i) {
      sum += cardPoints[i] - cardPoints[i - windowSize];
      minSum = min(minSum, sum);
    }
    return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
  }
};