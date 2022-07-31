// 两两交换链表中的节点
// https://leetcode.cn/problems/swap-nodes-in-pairs/
// INLINE  ../images/list/swap_nodes_in_pairs.jpeg
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
class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *pre = head->next;
    ListNode *next = pre->next;

    pre->next = head;
    head->next = swapPairs(next);

    return pre;
  }
};