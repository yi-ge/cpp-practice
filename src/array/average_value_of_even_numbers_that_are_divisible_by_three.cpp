// 可被三整除的偶数的平均值
// https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three
// INLINE
// ../../images/array/average_value_of_even_numbers_that_are_divisible_by_three.jpeg
#include <headers.hpp>

class Solution {
public:
  int averageValue(vector<int> &nums) {
    int sum = 0;  // 初始化数值总和为 0
    int count = 0;  // 初始化符合条件的数值个数为 0
    for (auto num : nums) {  // 遍历输入数组中的每一个数值
      // 只有两个条件都满足才加入
      if (num % 2 == 0 && num % 3 == 0) {  // 如果当前数值是偶数且能被 3 整除
        sum += num;  // 将当前数值加入到数值总和中
        count++;  // 将符合条件的数值个数加 1
      }
    }
    // 如果没有找到任何满足条件的数，返回 0，否则返回平均值
    return count == 0 ? 0 : sum / count;
  }
};