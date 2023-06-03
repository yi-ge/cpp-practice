// 通过翻转子数组使两个数组相等
// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays
// INLINE  ../../images/array/make_two_arrays_equal_by_reversing_sub_arrays.jpeg
#include <headers.hpp>

class Solution
{
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr)
  {
    // 统计target中每个数出现的次数
    unordered_map<int, int> count1;
    for (auto num : target)
    {
      count1[num]++;
    }

    // 统计arr中每个数出现的次数
    unordered_map<int, int> count2;
    for (auto num : arr)
    {
      count2[num]++;
    }

    // 若两个数组中不同的数的数量不同，则无法通过翻转子数组使两个数组相等，返回false
    if (count1.size() != count2.size())
    {
      return false;
    }

    // 对于每个数，如果它在target中出现的次数和在arr中出现的次数不同，则无法通过翻转子数组使两个数组相等，返回false
    for (auto &[key, value] : count1)
    {
      if (!count2.count(key) || count2[key] != value)
      {
        return false;
      }
    }

    return true;
  }
};