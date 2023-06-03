// 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/
// INLINE  ../../images/sort/merge_two_sorted_lists.jpeg
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
  // 合并两个有序链表
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // 如果list1为空，直接返回list2
    if (list1 == NULL) {
      return list2;
    }
    // 如果list2为空，直接返回list1
    if (list2 == NULL) {
      return list1;
    }
    // 如果list1的第一个节点比list2的第一个节点小或等于，则list1的第一个节点为合并后的链表的第一个节点，继续处理list1的下一个节点和list2
    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    // 如果list2的第一个节点比list1的第一个节点小，则list2的第一个节点为合并后的链表的第一个节点，继续处理list1和list2的下一个节点
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};