// 队列中可以看到的人数
// https://leetcode.cn/problems/number-of-visible-people-in-a-queue
// INLINE  ../../images/stack/number_of_visible_people_in_a_queue.jpeg

#include <headers.hpp>

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    int n = heights.size();
    vector<int> res(n, 0);
    vector<int> stack;

    for (int i = n - 1; i >= 0; i--) {
      int h = heights[i];
      while (!stack.empty() && stack.back() < h) {
        stack.pop_back();
        res[i] += 1;
      }
      if (!stack.empty()) {
        res[i] += 1;
      }
      stack.push_back(h);
    }
    return res;
  }
};