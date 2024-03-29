// 算术三元组的数目
// https://leetcode.cn/problems/number-of-arithmetic-triplets
// INLINE  ../../images/array/number_of_arithmetic_triplets.jpeg
#include <headers.hpp>

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    // 使用哈希表记录数组中的元素
    unordered_set<int> hashSet;
    for (int i : nums) {
      hashSet.emplace(i);
    }
    int ans = 0;
    // 遍历数组，查找是否存在满足条件的三元组
    for (int i : nums) {
      if (hashSet.count(i + diff) && hashSet.count(i + 2 * diff)) {
        ans++;
      }
    }
    return ans;
  }
};