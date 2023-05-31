// 优美的排列 II
// https://leetcode.cn/problems/beautiful-arrangement-ii
// INLINE  ../../images/array/beautiful_arrangement_ii.jpeg
// 解题思路：参阅
// https://leetcode.cn/problems/beautiful-arrangement-ii/solution/by-muse-77-5a56/
#include <headers.hpp>

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    int interval = k; // interval 为相邻元素的差值
    vector<int> ans;
    ans.push_back(1); // 初始化第一个元素为 1
    for (int i = 1; i <= k; i++) {
      // 下一个元素要么加上 interval，要么减去 interval
      // 我们希望序列中的元素交替出现
      // 如果 i 是奇数，我们要加上 interval
      // 如果 i 是偶数，我们要减去 interval
      ans.push_back(i % 2 == 1 ? ans[i - 1] + interval : ans[i - 1] - interval);
      interval--; // 每次 interval 减去 1
    }

    // 经过 k 次循环，我们得到了 k + 1 个元素
    // 下一个 k + 1 个元素就是依次加上 1
    k++;
    while (k < n) {
      ans.push_back(++k);
    }

    return ans;
  }
};