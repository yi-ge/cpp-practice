// 检查替换后的词是否有效
// https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions
// INLINE  ../../images/stack/check_if_word_is_valid_after_substitutions.jpeg
#include <headers.hpp>

class Solution {
public:
  bool isValid(string s) {
    std::stack<char> stack; // 创建一个字符栈
    for (auto c : s) { // 遍历字符串s中的每一个字符
      if (c == 'c') { // 如果当前字符为'c'
        if (stack.empty() || stack.top() != 'b') { // 如果栈为空或栈顶元素不为'b'
          return false; // 则替换后的词无效，返回false
        }
        stack.pop(); // 弹出栈顶元素
        if (stack.empty() || stack.top() != 'a') { // 如果栈为空或栈顶元素不为'a'
          return false; // 则替换后的词无效，返回false
        }
        stack.pop(); // 弹出栈顶元素
      } else { // 如果当前字符不为'c'
        stack.push(c); // 将当前字符入栈
      }
    }
    return stack.empty(); // 如果栈为空，则替换后的词有效，返回true；否则无效，返回false
  }
};