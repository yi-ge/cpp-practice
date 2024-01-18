// 拿出最少数目的魔法豆
// https://leetcode.cn/problems/removing-minimum-number-of-magic-beans
// INLINE  ../../images/sort/removing_minimum_number_of_magic_beans.jpeg

#include <headers.hpp>

class Solution {
public:
  long long minimumRemoval(vector<int> &beans) {
    int n = beans.size();
    sort(beans.begin(), beans.end());
    long long total = accumulate(beans.begin(), beans.end(), 0LL);
    long long res = total;
    for (int i = 0; i < n; i++) { // 遍历排序后的 beans 数组
      res = min(res, total - (long long)beans[i] * (n - i));
    }
    return res;
  }
};