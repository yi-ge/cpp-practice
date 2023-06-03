// 检查二进制字符串字段
// https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// INLINE
// ../../images/string/check_if_binary_string_has_at_most_one_segment_of_ones.jpeg
#include <headers.hpp>

class Solution {
public:
  // 判断二进制字符串s中是否包含"01"子串，如果不包含则说明只有一个1字段
  bool checkOnesSegment(string s) { return s.find("01") == string::npos; }
};