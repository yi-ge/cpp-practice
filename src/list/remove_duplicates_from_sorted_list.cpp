// 删除排序链表中的重复元素
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
// INLINE  ../../images/list/remove_duplicates_from_sorted_list.jpeg
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr &&
           cur->next != nullptr) { // 当链表不为空且当前节点不是最后一个节点时
      if (cur->next->val == cur->val) { // 当前节点的值与下一个节点的值相同时
        ListNode *deleteNode = cur->next; // 定义要删除的节点
        cur->next = cur->next->next; // 将当前节点指向下下个节点
        delete deleteNode;           // 删除要删除的节点
      } else {
        cur = cur->next; // 当前节点指向下一个节点
      }
    }

    return head; // 返回头节点
  }
};