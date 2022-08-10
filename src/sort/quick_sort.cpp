// 快速排序

#include <headers.hpp>

class Solution
{
public:
  void quickSort(vector<int> &nums)
  {
    quickSort(nums, 0, nums.size() - 1);
  }

private:
  int partition(vector<int> &nums, int l, int r)
  {
    int v = nums[l];

    int j = l;
    for (int i = l + 1; i <= r; ++i)
    {
      if (nums[i] < v)
        swap(nums[i], nums[++j]);
    }

    swap(nums[l], nums[j]);

    return j;
  }

  void quickSort(vector<int> &nums, int l, int r)
  {
    if (l >= r)
      return;
    int j = partition(nums, l, r);
    quickSort(nums, l, j - 1);
    quickSort(nums, j + 1, r);
  }
};