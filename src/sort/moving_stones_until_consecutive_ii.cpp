// 移动石子直到连续 II
// https://leetcode.cn/problems/moving-stones-until-consecutive-ii
// INLINE  ../../images/sort/moving_stones_until_consecutive_ii.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> numMovesStonesII(vector<int> &stones) {
    sort(stones.begin(), stones.end()); // 将石头位置从小到大排序
    int n = stones.size();
    // 计算最大值
    int maxn = max(stones[n - 1] - n + 2 - stones[1], // 最右边的石头往左移或最左边的石头往右移
                   stones[n - 2] - stones[0] - n + 2); // 最右边的石头往左移并且最左边的石头往右移
    int minn = maxn; // 初始最小值等于最大值
    int i = 0, j = 0; // 双指针，i指向区间左端点，j指向区间右端点
    while (j < n) {
      while (stones[j] - stones[i] + 1 > n) { // 区间长度大于等于n时缩小区间
        i++;
      }
      if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) { // 只有一个空位
        minn = min(minn, 2); // 只需要移动两次
      } else {
        minn = min(minn, n - (j - i + 1)); // 其他情况最小移动次数为n-区间长度
      }
      j++;
    }
    return {minn, maxn}; // 返回最小值和最大值
  }
};