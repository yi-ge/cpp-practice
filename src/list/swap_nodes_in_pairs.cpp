// 两两交换链表中的节点
// https://leetcode.cn/problems/swap-nodes-in-pairs/
// INLINE  ../../images/list/swap_nodes_in_pairs.jpeg
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
    // 如果链表为空或者只有一个节点，直接返回head
    if (!head || !head->next)
      return head;

    // 定义pre指向head的下一个节点，next指向pre的下一个节点
    ListNode *pre = head->next;
    ListNode *next = pre->next;

    // pre指向head，并递归处理下一个节点
    pre->next = head;
    head->next = swapPairs(next);

    // 返回pre
    return pre;
  }
};