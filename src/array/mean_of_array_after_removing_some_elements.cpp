// 删除某些元素后的数组均值
// https://leetcode-cn.com/problems/mean-of-array-after-removing-some-elements/
// INLINE  ../../images/array/mean_of_array_after_removing_some_elements.jpeg
#include <headers.hpp>
#include <numeric>

class Solution {
public:
  double trimMean(vector<int> &arr) {
    int len = arr.size(); // 数组长度
    sort(arr.begin(), arr.end()); // 对数组进行排序
    double res =
        accumulate(arr.begin() + len / 20, arr.begin() + 0.95 * len, 0); // 去掉前后各5%的元素后，求剩余元素的和
    return res / (len * 0.9); // 求剩余元素的平均值
  }
};