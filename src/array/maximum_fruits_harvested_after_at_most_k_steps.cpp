// 摘水果
// https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps
// INLINE ../../images/array/maximum_fruits_harvested_after_at_most_k_steps.jpeg
// 参考官方题解。
#include <headers.hpp>

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int left = 0;
    int right = 0;
    int n = fruits.size();
    int sum = 0;
    int ans = 0;

    auto step = [&](int left, int right) -> int {
      if (fruits[right][0] <= startPos) {
        return startPos - fruits[left][0];
      } else if (fruits[left][0] >= startPos) {
        return fruits[right][0] - startPos;
      } else {
        return min(abs(startPos - fruits[right][0]),
                   abs(startPos - fruits[left][0])) +
               fruits[right][0] - fruits[left][0];
      }
    };
    // 每次固定住窗口右边界
    while (right < n) {
      sum += fruits[right][1];
      // 移动左边界
      while (left <= right && step(left, right) > k) {
        sum -= fruits[left][1];
        left++;
      }
      ans = max(ans, sum);
      right++;
    }
    return ans;
  }
};