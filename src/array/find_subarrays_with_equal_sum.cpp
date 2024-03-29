// 和相等的子数组
// https://leetcode.cn/problems/find-subarrays-with-equal-sum
// INLINE  ../../images/array/find_subarrays_with_equal_sum.jpeg
#include <headers.hpp>

class Solution {
public:
  bool findSubarrays(std::vector<int> &nums) {
    int n = nums.size();
    if (n < 2) { // 如果数组长度小于2，则无法找到两个子数组
      return false;
    }

    std::unordered_map<int, int> sum_count; // 用于存储和出现的次数
    for (int i = 0; i < n - 1; ++i) { // 遍历数组，计算相邻两个数的和
      int sum = nums[i] + nums[i + 1];
      sum_count[sum]++; // 将和出现的次数加1
    }

    for (const auto &pair : sum_count) { // 遍历和出现次数的哈希表
      if (pair.second >=
          2) { // 如果某个和出现的次数大于等于2，则说明存在两个子数组的和相等
        return true;
      }
    }

    return false; // 如果没有找到两个子数组的和相等，则返回false
  }
};