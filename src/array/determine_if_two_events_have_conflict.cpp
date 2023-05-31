// 判断两个事件是否存在冲突
// https://leetcode.cn/problems/determine-if-two-events-have-conflict
// INLINE  ../../images/array/determine_if_two_events_have_conflict.jpeg
#include <headers.hpp>

class Solution {
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    // 事件1开始时间大于等于事件2的结束时间，或者事件1的结束时间小于等于事件2的开始时间，说明没有冲突
    return !(event1[1] < event2[0] || event2[1] < event1[0]);
  }
};