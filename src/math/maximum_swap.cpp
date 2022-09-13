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
    if (num < 10)
      return num;

    string str = to_string(num);
    for (int i = 0; i < str.size(); i++) {
      int max_index = i;
      for (int j = str.size() - 1; j > i; j--) {
        if (str[j] > str[max_index]) {
          max_index = j;
        }
      }

      if (max_index != i) {
        swap(str[max_index], str[i]);
        return atoi(str.c_str());
      }
    }

    return num;
  }
};