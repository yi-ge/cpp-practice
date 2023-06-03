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
    vector<int> result; // 存储答案的向量
    stack<int> s;       // 辅助用的栈
    int i = 0;          // 记录元素在链表中的下标
    while (head) {
      while (!s.empty() &&
             result[s.top()] < head->val) { // 当前节点的值大于栈顶元素
        result[s.top()] = head->val;        // 更新栈顶元素的答案
        s.pop();                            // 弹出栈顶元素
      }
      s.push(i++);                 // 将当前元素的下标推入栈中
      result.push_back(head->val); // 将当前元素的值加入答案向量中
      head = head->next;           // 移动到下一个节点
    }
    while (!s.empty()) {   // 处理栈中剩余的元素
      result[s.top()] = 0; // 对于没有更大节点的元素，答案为0
      s.pop();
    }
    return result; // 返回答案向量
  }
};