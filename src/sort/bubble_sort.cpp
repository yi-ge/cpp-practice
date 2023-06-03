// 冒泡排序

#include <headers.hpp>

class Solution
{
public:
  // 冒泡排序函数，输入为一个整数向量nums，返回排好序的向量
  vector<int> bubbleSort(vector<int> &nums)
  {
    // 外层循环控制循环次数，每循环一次，就会将一个最大的数放到最后
    for (int i = 0, len = nums.size() - 1; i < len; ++i)
    {
      // done标志位表示是否已经排好序，如果在内层循环中没有发生任何交换，则已经排好序，可以直接退出外层循环
      bool done = true;
      // 内层循环控制比较大小和交换位置
      for (int j = 0; j < len - i; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          swap(nums[j], nums[j + 1]);
          done = false;
        }
      }
      // 如果已经排好序，则退出循环
      if (done)
        break;
    }
    // 返回排好序的向量
    return nums;
  }
};