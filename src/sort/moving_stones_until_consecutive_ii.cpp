// 移动石子直到连续 II
// https://leetcode.cn/problems/moving-stones-until-consecutive-ii
// INLINE  ../../images/sort/moving_stones_until_consecutive_ii.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> numMovesStonesII(vector<int> &stones) {
    sort(stones.begin(), stones.end());
    int n = stones.size();
    int maxn = max(stones[n - 1] - n + 2 - stones[1],
                   stones[n - 2] - stones[0] - n + 2);
    int minn = maxn;
    int i = 0, j = 0;
    while (j < n) {
      while (stones[j] - stones[i] + 1 > n) {
        i++;
      }
      if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
        minn = min(minn, 2);
      } else {
        minn = min(minn, n - (j - i + 1));
      }
      j++;
    }
    return {minn, maxn};
  }
};