// 叶值的最小代价生成树
// https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values
// INLINE  ../../images/stack/minimum_cost_tree_from_leaf_values.jpeg
#include <headers.hpp>

class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int res = 0;
    stack<int> stk;
    stk.push(INT_MAX);
    for (int i = 0; i < arr.size(); ++i) {
      while (arr[i] >= stk.top()) {
        int mid = stk.top();
        stk.pop();
        res += mid * min(stk.top(), arr[i]);
      }
      stk.push(arr[i]);
    }
    while (stk.size() > 2) {
      int mid = stk.top();
      stk.pop();
      res += mid * stk.top();
    }
    return res;
  }
};