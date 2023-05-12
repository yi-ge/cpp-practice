// 与对应负数同时存在的最大正整数
// https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative
// INLINE
// ../../images/sort/largest_positive_integer_that_exists_with_its_negative.jpeg
#include <headers.hpp>

class Solution {
public:
  int findMaxK(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int max_k = -1;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == 0) {
        max_k = nums[j];
        break;
      } else if (nums[i] + nums[j] < 0) {
        i++;
      } else {
        j--;
      }
    }
    return max_k;
  }
};