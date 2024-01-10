// 删除子串后的字符串最小长度
// https://leetcode.cn/problems/minimum-string-length-after-removing-substrings
// INLINE
// ../../images/stack/minimum_string_length_after_removing_substrings.jpeg

#include <headers.hpp>

class Solution {
public:
  int minLength(string s) {
    vector<int> st;
    for (char c : s) {
      st.push_back(c);
      int m = st.size();
      if (m >= 2 && (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                     st[m - 2] == 'C' && st[m - 1] == 'D')) {
        st.pop_back();
        st.pop_back();
      }
    }
    return st.size();
  }
};