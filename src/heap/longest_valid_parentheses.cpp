// 最长有效括号
// https://leetcode.cn/problems/longest-valid-parentheses/
// INLINE  ../../images/heap/longest_valid_parentheses.jpeg
// 解题思路：利用“栈”这个数据结构。
#include <headers.hpp>

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int ans = 0;
    stack<int> stack; // 栈中存储的是下标，所以是int
    stack.push(-1);

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        stack.push(i);
      } else {
        stack.pop();
        if (stack.empty()) {
          stack.push(i); // 最后一个没有被匹配的右括号
        } else {
          ans = max(ans, i - stack.top()); // 当前右括号的下标减去栈顶元素
        }
      }
    }
    return ans;
  }
};