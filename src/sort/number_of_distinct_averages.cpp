// 不同的平均值数目
// https://leetcode.cn/problems/number-of-distinct-averages
// INLINE  ../../images/sort/number_of_distinct_averages.jpeg
#include <headers.hpp>

class Solution {
public:
  int distinctAverages(vector<int> &nums) {
    // 先排序
    sort(nums.begin(), nums.end());

    // 使用set保存结果
    unordered_set<int> res_set;

    // 从左右两边开始移动
    for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
      res_set.insert(nums[i] + nums[j]);
    }
    return res_set.size();
  }
};