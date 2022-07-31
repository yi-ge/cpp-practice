// 移除链表元素
// https://leetcode.cn/problems/remove-linked-list-elements/
// INLINE  ../images/list/remove_linked_list_elements.jpeg
#include <headers.hpp>

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while (cur->next != nullptr)
    {
      if (cur->next->val == val)
      {
        ListNode *deleteNode = cur->next;
        cur->next = cur->next->next;
        delete deleteNode;
      }
      else
      {
        cur = cur->next;
      }
    }

    ListNode *retNode = dummyHead->next;
    delete dummyHead;

    return retNode;
  }
};