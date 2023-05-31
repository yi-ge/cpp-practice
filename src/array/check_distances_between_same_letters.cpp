// 检查相同字母间的距离
// https://leetcode.cn/problems/check-distances-between-same-letters
// INLINE  ../../images/array/check_distances_between_same_letters.jpeg
#include <headers.hpp>

class Solution {
public:
  // distance 是一个整数数组，其中的元素表示每个字母之间的最大距离。
  // 如果字符串 s 满足以下条件，则返回 true：
  // 1. s 的长度为 n，distance 的长度为 m；
  // 2. s[i] == s[j] 且 |i - j| < distance[s[i] - 'a'] 对于所有的 0 <= i < j < n
  // 都成立。
  bool checkDistances(string s, vector<int> &distance) {
    int n = s.size();
    int m = distance.size();
    // last[i] 表示字符 i 最后出现的位置。
    vector<int> last(m, -1);
    for (int i = 0; i < n; ++i) {
      int x = s[i] - 'a';
      if (last[x] != -1 && i - last[x] - 1 != distance[x]) {
        return false;
      }
      last[x] = i;
    }
    return true;
  }
};