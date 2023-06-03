// 检查相同字母间的距离
// https://leetcode.cn/problems/check-distances-between-same-letters
// INLINE  ../../images/array/check_distances_between_same_letters.jpeg
#include <headers.hpp>

class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    int n = s.size();
    int m = distance.size();
    // last[i] 表示字符 i 最后出现的位置。
    vector<int> last(m, -1);
    // 遍历字符串 s，更新 last 数组
    for (int i = 0; i < n; ++i) {
      int x = s[i] - 'a';
      // 如果字符 x 已经出现过，检查距离是否符合要求
      if (last[x] != -1 && i - last[x] - 1 != distance[x]) {
        return false;
      }
      last[x] = i;
    }
    return true;
  }
};