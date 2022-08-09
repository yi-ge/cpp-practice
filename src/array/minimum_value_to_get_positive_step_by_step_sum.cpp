// 逐步求和得到正数的最小值
// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum
// INLINE  ../images/array/minimum_value_to_get_positive_step_by_step_sum.jpeg
// 这题的关键在于理解题意，参阅官方题解。
#include <headers.hpp>

class Solution
{
public:
  int minStartValue(vector<int> &nums)
  {
    int current = 0;
    int min = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      current += nums[i];
      if (current < min)
      {
        min = current;
      }
    }
    return abs(min) + 1;
  }
};