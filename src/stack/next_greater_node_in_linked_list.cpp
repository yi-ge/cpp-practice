// 链表中的下一个更大节点
// https://leetcode.cn/problems/next-greater-node-in-linked-list
// INLINE  ../../images/stack/next_greater_node_in_linked_list.jpeg
#include <headers.hpp>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> result;
    stack<int> s;
    int i = 0;
    while (head) {
      while (!s.empty() && result[s.top()] < head->val) {
        result[s.top()] = head->val;
        s.pop();
      }
      s.push(i++);
      result.push_back(head->val);
      head = head->next;
    }
    while (!s.empty()) {
      result[s.top()] = 0;
      s.pop();
    }
    return result;
  }
};