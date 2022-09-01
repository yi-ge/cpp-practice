// 找到小镇的法官
// https://leetcode.cn/problems/find-the-town-judge
// INLINE  ../../images/graphs/find_the_town_judge.jpeg
#include <headers.hpp>

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> inDegrees(n + 1);
    vector<int> outDegrees(n + 1);

    for (auto &edge : trust)
    {
      ++inDegrees[edge[1]];
      ++outDegrees[edge[0]];
    }

    for (int i = 1; i <= n; ++i)
    {
      if (inDegrees[i] == n - 1 && outDegrees[i] == 0)
      {
        return i;
      }
    }

    return -1;
  }
};