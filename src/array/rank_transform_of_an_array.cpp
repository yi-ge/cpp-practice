// 数组序号转换
// https://leetcode.cn/problems/rank-transform-of-an-array
// INLINE  ../../images/array/rank_transform_of_an_array.jpeg
#include <headers.hpp>

class Solution
{
public:
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    vector<int> sArr = arr;
    sort(sArr.begin(), sArr.end());
    unordered_map<int, int> ranks;
    vector<int> ans(arr.size());
    for (auto &a : sArr)
    {
      if (!ranks.count(a))
      {
        ranks[a] = ranks.size() + 1;
      }
    }
    for (int i = 0; i < arr.size(); i++)
    {
      ans[i] = ranks[arr[i]];
    }
    return ans;
  }
};