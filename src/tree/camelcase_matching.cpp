// 驼峰式匹配
// https://leetcode.cn/problems/camelcase-matching
// INLINE  ../../images/tree/camelcase_matching.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    int n = queries.size();
    vector<bool> res(n, true); // 初始化结果数组

    for (int i = 0; i < n; ++i) { // 遍历每个查询字符串
      int p = 0;                  // 初始化模式串的指针
      for (auto c : queries[i]) { // 遍历当前查询字符串的每个字符
        if (p < pattern.size() &&
            pattern[p] == c) { // 如果模式串的指针未越界且与当前字符匹配
          ++p;                 // 模式串指针向后移动
        } else if (isupper(c)) { // 如果当前字符为大写字母
          res[i] = false; // 当前查询字符串不匹配，将结果设置为false
          break;          // 跳出循环
        }
      }
      if (p < pattern.size()) { // 如果模式串的指针未移动到模式串末尾
        res[i] = false; // 当前查询字符串不匹配，将结果设置为false
      }
    }

    return res; // 返回结果数组
  }
};