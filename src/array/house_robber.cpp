// 打家劫舍
// https://leetcode.cn/problems/house-robber
// INLINE  ../../images/array/house_robber.jpeg

#include <headers.hpp>

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    int dp_i_1 = 0, dp_i_2 = 0;
    int dp_i = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp_i = max(dp_i_1, nums[i] + dp_i_2);
      dp_i_2 = dp_i_1;
      dp_i_1 = dp_i;
    }
    return dp_i;
  }
};