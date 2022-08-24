// 通过翻转子数组使两个数组相等
// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays
// INLINE  ../../images/array/make_two_arrays_equal_by_reversing_sub_arrays.jpeg
#include <headers.hpp>

class Solution
{
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr)
  {
    unordered_map<int, int> count1, count2;
    for (auto num : target)
    {
      count1[num]++;
    }

    for (auto num : arr)
    {
      count2[num]++;
    }

    if (count1.size() != count2.size())
    {
      return false;
    }

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