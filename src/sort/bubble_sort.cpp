// 冒泡排序

#include <headers.hpp>

class Solution
{
public:
  vector<int> bubbleSort(vector<int> &nums)
  {
    for (int i = 0, len = nums.size() - 1; i < len; ++i)
    {
      bool done = true;
      for (int j = 0; j < len - i; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          swap(nums[j], nums[j + 1]);
          done = false;
        }
      }
      if (done)
        break;
    }
    return nums;
  }
};