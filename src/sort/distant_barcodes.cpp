// 距离相等的条形码
// https://leetcode.cn/problems/distant-barcodes
// INLINE  ../../images/sort/distant_barcodes.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    unordered_map<int, int> count;
    for (int b : barcodes) {
      count[b]++;
    }
    priority_queue<pair<int, int>> q;
    for (const auto &[x, cx] : count) {
      q.push({cx, x});
    }
    vector<int> res;
    while (!q.empty()) {
      auto [cx, x] = q.top();
      q.pop();
      if (res.empty() || res.back() != x) {
        res.push_back(x);
        if (cx > 1) {
          q.push({cx - 1, x});
        }
      } else {
        // if (q.empty())
        //   return res;
        auto [cy, y] = q.top();
        q.pop();
        res.push_back(y);
        if (cy > 1) {
          q.push({cy - 1, y});
        }
        q.push({cx, x});
      }
    }
    return res;
  }
};