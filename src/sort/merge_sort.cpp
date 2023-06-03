// 归并排序

#include <headers.hpp>

class Solution
{
public:
  // 归并排序函数，返回排序后的数组
  vector<int> mergeSort(vector<int> &nums)
  {
    // 数组大小小于等于1时直接返回
    if (nums.size() <= 1)
      return nums;
    // 找到数组中间位置
    int halfIndex = floor(nums.size() / 2);
    // 将左半部分赋值给left
    vector<int> left;
    left.assign(nums.begin(), nums.begin() + halfIndex);
    // 将右半部分赋值给right
    vector<int> right;
    right.assign(nums.begin() + halfIndex, nums.end());
    // 递归调用归并排序函数对左右两部分分别排序
    vector<int> leftSort = mergeSort(left);
    vector<int> rightSort = mergeSort(right);
    // 将排序后的左右两部分合并
    return marge(leftSort, rightSort);
  }

private:
  // 合并两个有序数组为一个有序数组
  vector<int> marge(vector<int> &left, vector<int> &right)
  {
    vector<int> res;
    // 当左右两个数组都不为空时
    while (left.size() > 0 && right.size() > 0)
    {
      // 将左右两个数组中较小的元素加入结果数组中
      if (left[0] < right[0])
      {
        res.push_back(left[0]);
        // 删除已经加入结果数组的元素
        vector<int>::iterator k = left.begin();
        left.erase(k);
      }
      else
      {
        res.push_back(right[0]);
        vector<int>::iterator j = right.begin();
        right.erase(j);
      }
    }
    // 将左右两个数组中剩余的元素加入结果数组中
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
  }
};