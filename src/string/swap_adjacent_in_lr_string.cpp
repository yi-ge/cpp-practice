// 在LR字符串中交换相邻字符
// https://leetcode.cn/problems/swap-adjacent-in-lr-string
// INLINE  ../../images/string/swap_adjacent_in_lr_string.jpeg
// 解题思路：不需要真的去交换字符，只需要判断相对顺序是否一致且满足交换条件。
#include <headers.hpp>

class Solution {
public:
  bool canTransform(string start, string end) {
    int len = end.length();
    int i = 0, j = 0;
    while (i < len && j < len) {
      while (i < len && start[i] == 'X') { // 找到start中第一个不是'X'的字符
        i++;
      }

      while (j < len && end[j] == 'X') { // 找到end中第一个不是'X'的字符
        j++;
      }

      if (i < len && j < len) {
        if (start[i] !=
            end[j]) { // 如果两个字符不相同，则无法通过交换相邻字符得到end
          return false;
        }
        // 判断是否满足交换条件
        // XXL
        // XLX
        // XXR
        // XRX
        // if (i >= j && start[i] == 'L' || (i <= j && start[i] == 'R')) {
        if ((i < j && start[i] == 'L') || (i > j && start[i] == 'R')) {
          return false;
        }
        i++; // 继续比较下一个字符
        j++;
      }
    }

    // 没有下面的判断会导致只有一个字符的时候错误 例如："X"，"L"
    while (
        i <
        len) { // 如果start中还剩下不是'X'的字符，则无法通过交换相邻字符得到end
      if (start[i] != 'X') {
        return false;
      }
      i++;
    }
    while (j <
           len) { // 如果end中还剩下不是'X'的字符，则无法通过交换相邻字符得到end
      if (end[j] != 'X') {
        return false;
      }
      j++;
    }
    return true; // 成功通过交换相邻字符得到end
  }
};