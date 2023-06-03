// 数组序号转换
// https://leetcode.cn/problems/rank-transform-of-an-array
// INLINE  ../../images/array/rank_transform_of_an_array.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sArr = arr;         // 复制原数组
    sort(sArr.begin(), sArr.end()); // 对复制数组进行排序
    unordered_map<int, int> ranks;  // 记录每个元素的排名
    vector<int> ans(arr.size());    // 存储排名后的结果
    for (auto &a : sArr) {
      if (!ranks.count(a)) // 如果该元素还未出现过
      {
        ranks[a] = ranks.size() + 1; // 给它一个排名
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      ans[i] = ranks[arr[i]]; // 获取原数组每个元素的排名
    }
    return ans; // 返回排名后的结果
  }
};