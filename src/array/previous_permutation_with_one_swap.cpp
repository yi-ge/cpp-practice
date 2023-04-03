// 交换一次的先前排列
// https://leetcode.cn/problems/previous-permutation-with-one-swap
// INLINE  ../../images/array/previous_permutation_with_one_swap.jpeg
// 对当前序列进行逆序查找，找到第一个降序的位置 i， 寻找在 A[i] 右边且小于 A[i]
// 的最大的数字 A[j]
#include <headers.hpp>

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    int len = arr.size();
    int curMax = -1;
    int index = -1;
    bool hasResult = false;
    for (int i = len - 2; i >= 0; i--) {
      if (arr[i + 1] < arr[i]) {

        for (int j = i + 1; j < len; j++) {
          if (arr[i] > arr[j]) {

            hasResult = true;
            if (arr[j] > curMax) {

              curMax = arr[j];
              index = j;
            }
          }
        }
        if (hasResult) {
          int tmp = arr[i];
          arr[i] = arr[index];
          arr[index] = tmp;
          return arr;
        }
      } // LCOV_EXCL_LINE
    }
    return arr;
  }
};