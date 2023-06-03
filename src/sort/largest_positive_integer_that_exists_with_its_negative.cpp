// 与对应负数同时存在的最大正整数
// https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative
// INLINE
// ../../images/sort/largest_positive_integer_that_exists_with_its_negative.jpeg
#include <headers.hpp>

class Solution {
public:
  // 寻找最大的k，使得-k存在于nums中
  int findMaxK(vector<int> &nums) {
    // 从小到大排序
    std::sort(nums.begin(), nums.end());
    int max_k = -1;
    int i = 0;
    int j = nums.size() - 1;
    // 双指针寻找最大的k
    while (i < j) {
      if (nums[i] + nums[j] == 0) {
        // 如果i和j的和为0，则说明-k存在于nums中，返回j即可
        max_k = nums[j];
        break;
      } else if (nums[i] + nums[j] < 0) {
        // 如果i和j的和小于0，则说明i需要向右移动
        i++;
      } else {
        // 如果i和j的和大于0，则说明j需要向左移动
        j--;
      }
    }
    return max_k;
  }
};