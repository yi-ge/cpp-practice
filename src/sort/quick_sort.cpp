// 快速排序

#include <headers.hpp>

class Solution
{
public:
  // 对给定数组进行快速排序
  void quickSort(vector<int> &nums)
  {
    quickSort(nums, 0, nums.size() - 1);
  }

private:
  // 对数组nums的[l, r]部分进行partition操作，并返回pivot的下标
  int partition(vector<int> &nums, int l, int r)
  {
    // 选择第一个元素作为pivot
    int v = nums[l];

    // [l+1, j]表示小于v的部分，(j, i]表示大于等于v的部分
    int j = l;
    for (int i = l + 1; i <= r; ++i)
    {
      if (nums[i] < v)
        swap(nums[i], nums[++j]); // 将小于v的元素交换到[l+1, j]位置
    }

    swap(nums[l], nums[j]); // 将pivot交换到正确的位置

    return j;
  }

  // 对数组nums的[l, r]部分进行快速排序
  void quickSort(vector<int> &nums, int l, int r)
  {
    if (l >= r)
      return;
    int j = partition(nums, l, r); // 对当前部分进行partition操作，得到pivot的下标
    quickSort(nums, l, j - 1); // 对pivot左侧部分进行递归排序
    quickSort(nums, j + 1, r); // 对pivot右侧部分进行递归排序
  }
};