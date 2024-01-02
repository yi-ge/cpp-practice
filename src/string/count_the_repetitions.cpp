// 统计重复个数
// https://leetcode.cn/problems/count-the-repetitions
// INLINE  ../../images/string/count_the_repetitions.jpeg

#include <headers.hpp>

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int index1 = 0;
    int index2 = 0;

    if (len1 == 0 || len2 == 0 || len1 * n1 < len2 * n2) {
      return 0;
    }

    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    int ans = 0;

    while (index1 / len1 < n1) {
      if (index1 % len1 == len1 - 1) {
        if (map1.count(index2 % len2)) {
          int cycleLen = index1 / len1 - map1[index2 % len2] / len1;
          int cycleNum = (n1 - 1 - index1 / len1) / cycleLen;
          int cycleS2Num = index2 / len2 - map2[index2 % len2] / len2;

          index1 += cycleNum * cycleLen * len1;
          ans += cycleNum * cycleS2Num;
        } else {
          map1[index2 % len2] = index1;
          map2[index2 % len2] = index2;
        }
      }

      if (s1[index1 % len1] == s2[index2 % len2]) {
        if (index2 % len2 == len2 - 1) {
          ans += 1;
        }
        index2 += 1;
      }
      index1 += 1;
    }
    return ans / n2;
  }
};