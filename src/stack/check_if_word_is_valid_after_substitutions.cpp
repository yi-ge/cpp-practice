// 检查替换后的词是否有效
// https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions
// INLINE  ../../images/stack/check_if_word_is_valid_after_substitutions.jpeg
#include <headers.hpp>

class Solution {
public:
  bool isValid(string s) {
    std::stack<char> stack;
    for (auto c : s) {
      if (c == 'c') {
        if (stack.empty() || stack.top() != 'b') {
          return false;
        }
        stack.pop();
        if (stack.empty() || stack.top() != 'a') {
          return false;
        }
        stack.pop();
      } else {
        stack.push(c);
      }
    }
    return stack.empty();
  }
};