// 优美的排列 II
// https://leetcode.cn/problems/beautiful-arrangement-ii
// INLINE  ../../images/array/beautiful_arrangement_ii.jpeg
// 解题思路：参阅
// https://leetcode.cn/problems/beautiful-arrangement-ii/solution/by-muse-77-5a56/
#include <headers.hpp>

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    int interval = k;
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i <= k; i++) {
      ans.push_back(i % 2 == 1 ? ans[i - 1] + interval : ans[i - 1] - interval);
      interval--;
    }

    k++;
    while (k < n) {
      ans.push_back(++k);
    }

    return ans;
  }
};