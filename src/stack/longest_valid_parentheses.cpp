// 最长有效括号
// https://leetcode.cn/problems/longest-valid-parentheses/
// INLINE  ../../images/stack/longest_valid_parentheses.jpeg
// 解题思路：利用“栈”这个数据结构。

#include <headers.hpp>

class Solution {
public:
  int longestValidParentheses(string s) {
    int ans = 0;
    stack<int> stack; // 栈中存储的是下标，所以是int
    stack.push(-1); // 初始化栈，-1表示最开始还没有左括号与之匹配

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') // 左括号入栈
      {
        stack.push(i);
      } else // 右括号
      {
        stack.pop(); // 匹配一个左括号
        if (stack.empty()) // 栈为空，说明当前右括号没有匹配的左括号
        {
          stack.push(i); // 将当前右括号下标入栈，作为新的“没有匹配的右括号”
        } else // 栈不为空，计算当前匹配的括号序列的长度
        {
          ans = max(ans, i - stack.top()); // 当前右括号的下标减去栈顶元素
        }
      }
    }
    return ans;
  }
};