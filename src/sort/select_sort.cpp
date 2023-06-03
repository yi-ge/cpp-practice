// 选择排序

#include <headers.hpp>

class Solution
{
public:
  vector<int> selectSort(vector<int> &nums)
  {
    for (int i = 0, len = nums.size(); i < len; ++i) // 外层循环，从第一个数开始，一直到倒数第二个数
    {
      int minIndex = i; // 假设当前位置的数就是最小值
      for (int j = i + 1; j < len; j++) // 内层循环，从当前位置的下一个位置开始，一直到最后一个数
      {
        if (nums[j] < nums[minIndex]) // 如果找到比当前位置的数更小的数
        {
          minIndex = j; // 更新最小值的位置
        }
      }
      swap(nums[minIndex], nums[i]); // 将最小值和当前位置的数交换
    }
    return nums; // 返回排序后的数组
  }
};