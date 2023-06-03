// 交换一次的先前排列
// https://leetcode.cn/problems/previous-permutation-with-one-swap
// INLINE  ../../images/array/previous_permutation_with_one_swap.jpeg
// 对当前序列进行逆序查找，找到第一个降序的位置 i， 寻找在 A[i] 右边且小于 A[i]
// 的最大的数字 A[j]
#include <headers.hpp>

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    int len = arr.size(); // 获取数组长度
    int curMax = -1; // 当前最大值初始化为-1
    int index = -1; // 最大值下标初始化为-1
    bool hasResult = false; // 是否找到合适的结果
    for (int i = len - 2; i >= 0; i--) { // 从倒数第二个数开始向前遍历
      if (arr[i + 1] < arr[i]) { // 如果后一个数比前一个数小，说明找到了第一个降序的位置

        for (int j = i + 1; j < len; j++) { // 在降序位置右侧遍历
          if (arr[i] > arr[j]) { // 如果找到比降序位置数更小的数

            hasResult = true; // 标记已找到结果
            if (arr[j] > curMax) { // 如果比当前最大值还大

              curMax = arr[j]; // 更新最大值
              index = j; // 记录下标
            }
          }
        }
        if (hasResult) { // 如果找到了合适的数

          int tmp = arr[i];
          arr[i] = arr[index]; // 交换位置
          arr[index] = tmp;
          return arr;
        }
      } // LCOV_EXCL_LINE
    }
    return arr;
  }
};