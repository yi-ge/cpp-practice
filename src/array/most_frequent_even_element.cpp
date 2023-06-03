// 出现最频繁的偶数元素
// https://leetcode.cn/problems/most-frequent-even-element
// INLINE  ../../images/array/most_frequent_even_element.jpeg
#include <headers.hpp>

class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    int max = 0; // 最大出现次数
    int maxNum = -1; // 出现次数最多的偶数
    unordered_map<int, int> map; // 建立映射关系，记录每个数出现的次数
    sort(nums.begin(), nums.end()); // 对数组进行排序
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) { // 如果是偶数
        map[nums[i]]++; // 记录该数出现的次数
        if (map[nums[i]] > max) { // 如果该数出现次数大于当前最大出现次数
          max = map[nums[i]]; // 更新最大出现次数
          maxNum = nums[i]; // 更新最大出现次数对应的偶数
        }
      }
    }
    return maxNum; // 返回出现次数最多的偶数
  }
};