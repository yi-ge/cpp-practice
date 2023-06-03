// 距离相等的条形码
// https://leetcode.cn/problems/distant-barcodes
// INLINE  ../../images/sort/distant_barcodes.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    // 统计每个条形码数量
    unordered_map<int, int> count;
    for (int b : barcodes) {
      count[b]++;
    }
    // 优先队列，存储条形码数量和对应的条形码
    priority_queue<pair<int, int>> q;
    for (const auto &[x, cx] : count) {
      q.push({cx, x});
    }
    // 重新排列条形码
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
        // 如果当前条形码和上一个相同，取出下一个数量最多的条形码插入
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