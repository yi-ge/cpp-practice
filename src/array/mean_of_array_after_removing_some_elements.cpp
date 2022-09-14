// 删除某些元素后的数组均值
// https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/
// INLINE  ../../images/array/mean_of_array_after_removing_some_elements.jpeg
#include <headers.hpp>
#include <numeric>

class Solution {
public:
  double trimMean(vector<int> &arr) {
    int len = arr.size();
    sort(arr.begin(), arr.end());
    double res =
        accumulate(arr.begin() + len / 20, arr.begin() + 0.95 * len, 0);
    return res / (len * 0.9);
  }
};