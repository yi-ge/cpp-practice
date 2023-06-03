// 叶值的最小代价生成树
// https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values
// INLINE  ../../images/stack/minimum_cost_tree_from_leaf_values.jpeg

#include <headers.hpp>

class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int res = 0; // 初始化代价为0
    stack<int> stk;
    stk.push(INT_MAX); // 压入一个非常大的数，保证所有数都会被弹出
    for (int i = 0; i < arr.size(); ++i) {
      while (arr[i] >= stk.top()) { // 如果当前数比栈顶元素大，则弹出栈顶元素
        int mid = stk.top();
        stk.pop();
        res += mid * min(stk.top(), arr[i]); // 计算代价
      }
      stk.push(arr[i]); // 压入当前数
    }
    while (stk.size() > 2) { // 栈中还剩两个及以上元素，继续弹出计算代价
      int mid = stk.top();
      stk.pop();
      res += mid * stk.top();
    }
    return res; // 返回最小代价
  }
};