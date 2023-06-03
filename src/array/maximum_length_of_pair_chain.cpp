// 最长数对链
// https://leetcode.cn/problems/maximum-length-of-pair-chain
// INLINE  ../../images/array/maximum_length_of_pair_chain.jpeg
#include <headers.hpp>

class Solution
{
public:
  // 找出最长的数对链
  int findLongestChain(vector<vector<int>> &pairs)
  {
    int curr = INT_MIN, ans = 0;
    // 按数对的第二个元素排序
    sort(pairs.begin(), pairs.end(), [](auto &&a, auto &&b) -> bool
         { return a[1] < b[1]; });
    // 遍历每个数对，如果当前数对的第一个元素大于前一个数对的第二个元素，则更新当前数对的第二个元素和答案
    for (auto &pair : pairs)
    {
      if (pair[0] > curr)
      {
        curr = pair[1];
        ans++;
      }
    }

    return ans;
  }
};