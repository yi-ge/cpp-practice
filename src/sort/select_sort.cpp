// 选择排序

#include <headers.hpp>

class Solution
{
public:
  vector<int> selectSort(vector<int> &nums)
  {
    for (int i = 0, len = nums.size(); i < len; ++i)
    {
      int minIndex = i;
      for (int j = i + 1; j < len; j++)
      {
        if (nums[j] < nums[minIndex])
        {
          minIndex = j;
        }
      }
      swap(nums[minIndex], nums[i]);
    }
    return nums;
  }
};