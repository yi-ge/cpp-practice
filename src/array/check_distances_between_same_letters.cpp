// 检查相同字母间的距离
// https://leetcode.cn/problems/check-distances-between-same-letters
// INLINE  ../../images/array/check_distances_between_same_letters.jpeg
#include <headers.hpp>

class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    int n = s.size();
    int m = distance.size();
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