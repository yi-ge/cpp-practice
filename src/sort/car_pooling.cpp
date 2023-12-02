// 拼车
// https://leetcode.cn/problems/car-pooling
// INLINE  ../../images/sort/car_pooling.jpeg

#include <headers.hpp>

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> timestamp(1001, 0);
    for (auto &trip : trips) {
      timestamp[trip[1]] += trip[0];
      timestamp[trip[2]] -= trip[0];
    }
    int ued_capacity = 0;
    for (auto &number : timestamp) {
      ued_capacity += number;
      if (ued_capacity > capacity) {
        return false;
      }
    }
    return true;
  }
};