// 插入排序

#include <headers.hpp>

class Solution
{
public:
  // 插入排序函数
  vector<int> insertSort(vector<int> &nums)
  {
    // 外层循环，从第一个元素开始遍历
    for (int i = 0; i < nums.size(); ++i)
    {
      // 内层循环，将当前元素插入已排序好的数组中
      for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--)
      {
        // 若前一个元素大于当前元素，则交换它们的位置
        swap(nums[j], nums[j - 1]);
      }
    }
    // 返回排序好的数组
    return nums;
  }
};