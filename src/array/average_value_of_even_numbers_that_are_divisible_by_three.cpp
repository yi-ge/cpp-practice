// 可被三整除的偶数的平均值
// https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three
// INLINE
// ../../images/array/average_value_of_even_numbers_that_are_divisible_by_three.jpeg
#include <headers.hpp>

class Solution {
public:
  int averageValue(vector<int> &nums) {
    int sum = 0;
    int count = 0;
    for (auto num : nums) {
      if (num % 2 == 0 && num % 3 == 0) {
        sum += num;
        count++;
      }
    }
    return count == 0 ? 0 : sum / count;
  }
};