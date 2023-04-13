// 出现最频繁的偶数元素
// https://leetcode.cn/problems/most-frequent-even-element
// INLINE  ../../images/array/most_frequent_even_element.jpeg
#include <headers.hpp>

class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    int max = 0;
    int maxNum = -1;
    unordered_map<int, int> map;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) {
        map[nums[i]]++;
        if (map[nums[i]] > max) {
          max = map[nums[i]];
          maxNum = nums[i];
        }
      }
    }
    return maxNum;
  }
};