// 对数组执行操作
// https://leetcode.cn/problems/apply-operations-to-an-array
// INLINE  ../../images/array/apply_operations_to_an_array.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    int n = nums.size();
    // 遍历数组
    for (int i = 0, j = 0; i < n; i++) {
      // 检查两个相邻的数字是否相等
      if (i + 1 < n && nums[i] == nums[i + 1]) {
        // 将他们相加
        nums[i] *= 2;
        // 将其中一个设置为0
        nums[i + 1] = 0;
      }
      // 检查当前数字是否不为0
      if (nums[i] != 0) {
        // 将当前数字与数组开头的数字交换
        swap(nums[i], nums[j]);
        // 增加数组开头的下标
        j++;
      }
    }
    return nums;
  }
};