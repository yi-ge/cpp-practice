// 逐步求和得到正数的最小值
// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum
// INLINE  ../../images/array/minimum_value_to_get_positive_step_by_step_sum.jpeg
// 这题的关键在于理解题意，参阅官方题解。

#include <headers.hpp>

class Solution
{
public:
  int minStartValue(vector<int> &nums)
  {
    int current = 0; // 记录当前的累加和
    int min = 0; // 记录历史的最小累加和
    for (int i = 0; i < nums.size(); ++i)
    {
      current += nums[i]; // 累加当前数
      if (current < min) // 如果当前累加和比历史最小累加和更小
      {
        min = current; // 更新历史最小累加和
      }
    }
    return abs(min) + 1; // 返回最小起始值，即历史最小累加和的相反数加1
  }
};