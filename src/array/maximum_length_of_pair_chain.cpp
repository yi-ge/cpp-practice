// 最长数对链
// https://leetcode.cn/problems/maximum-length-of-pair-chain
// INLINE  ../../images/array/maximum_length_of_pair_chain.jpeg
#include <headers.hpp>

class Solution
{
public:
  int findLongestChain(vector<vector<int>> &pairs)
  {
    int curr = INT_MIN, ans = 0;
    sort(pairs.begin(), pairs.end(), [](auto &&a, auto &&b) -> bool
         { return a[1] < b[1]; });
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