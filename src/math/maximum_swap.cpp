// 最大交换
// https://leetcode.cn/problems/maximum-swap/
// INLINE  ../../images/math/maximum_swap.jpeg
// 解题思路：选择排序

#include <algorithm>
#include <headers.hpp>
#include <string>

class Solution {
public:
  int maximumSwap(int num) {
    // 如果num小于10，则直接返回num
    if (num < 10)
      return num;

    // 将num转化为字符串类型
    string str = to_string(num);
    for (int i = 0; i < str.size(); i++) {
      int max_index = i;
      for (int j = str.size() - 1; j > i; j--) {
        // 找到字符串中最大的数值，并记录它的下标
        if (str[j] > str[max_index]) {
          max_index = j;
        }
      }

      // 如果最大值的下标不是i，则交换i和最大值下标对应的值，并返回转化为整型后的字符串
      if (max_index != i) {
        swap(str[max_index], str[i]);
        return atoi(str.c_str());
      }
    }

    // 如果不存在交换，则直接返回原数值
    return num;
  }
};