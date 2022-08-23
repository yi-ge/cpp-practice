// 插入排序

#include <headers.hpp>

class Solution
{
public:
  vector<int> insertSort(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--)
      {
        swap(nums[j], nums[j - 1]);
      }
    }
    return nums;
  }
};