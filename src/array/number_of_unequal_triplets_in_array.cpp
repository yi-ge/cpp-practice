// 数组中不等三元组的数目
// https://leetcode.cn/problems/number-of-unequal-triplets-in-array
// INLINE  ../../images/array/number_of_unequal_triplets_in_array.jpeg

#include <headers.hpp>

class Solution {
public:
  int unequalTriplets(vector<int> &nums) {
    // 先对数组进行排序
    sort(nums.begin(), nums.end());
    // count用来记录不等三元组的个数
    int count = 0, n = nums.size();
    // 遍历数组
    for (int i = 0, j = 0; i < n; i = j) {
      // j用来记录和nums[i]相等的最后一个元素的下一个位置
      while (j < n && nums[j] == nums[i]) {
        j++;
      }
      // nums[i]和nums[j]之间的元素都和nums[i]相等
      // 从nums[i]中选出两个元素，从nums[j]中选出一个元素
      // 有i*(j-i)*(n-j)种选择
      count += i * (j - i) * (n - j);
    }
    return count;
  }
};