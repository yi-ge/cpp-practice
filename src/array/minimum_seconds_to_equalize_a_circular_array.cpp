// 使循环数组所有元素相等的最少秒数
// https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array
// INLINE  ../../images/array/minimum_seconds_to_equalize_a_circular_array.jpeg

#include <headers.hpp>

class Solution {
public:
  int minimumSeconds(vector<int> &nums) {
    unordered_map<int, vector<int>> map;
    int n = nums.size(), res = n;
    for (int i = 0; i < n; ++i) {
      map[nums[i]].push_back(i);
    }
    for (auto &pos : map) {
      int mx = pos.second[0] + n - pos.second.back();
      for (int i = 1; i < pos.second.size(); ++i) {
        mx = max(mx, pos.second[i] - pos.second[i - 1]);
      }
      res = min(res, mx / 2);
    }
    return res;
  }
};