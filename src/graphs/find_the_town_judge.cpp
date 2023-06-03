// 找到小镇的法官
// https://leetcode.cn/problems/find-the-town-judge
// INLINE  ../../images/graphs/find_the_town_judge.jpeg
#include <headers.hpp>

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> inDegrees(n + 1); // 入度数组，记录每个人被信任的次数
    vector<int> outDegrees(n + 1); // 出度数组，记录每个人信任别人的次数

    for (auto &edge : trust) // 遍历所有信任关系
    {
      ++inDegrees[edge[1]]; // 被信任者入度加一
      ++outDegrees[edge[0]]; // 信任者出度加一
    }

    for (int i = 1; i <= n; ++i) // 遍历所有人
    {
      if (inDegrees[i] == n - 1 && outDegrees[i] == 0) // 如果某个人入度为 n-1，出度为 0，说明他是法官
      {
        return i;
      }
    }

    return -1; // 没有法官，返回 -1
  }
};