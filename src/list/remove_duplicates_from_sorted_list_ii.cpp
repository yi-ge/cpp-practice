// 删除排序链表中的重复元素 II
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
// INLINE  ../images/list/remove_duplicates_from_sorted_list_ii.jpeg
#include <headers.hpp>
#include <list_node.hpp>

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
  ListNode *deleteDuplicates2(ListNode *head)
  {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *pre = dummyHead;
    ListNode *cur = head;
    while (cur->next != nullptr)
    {
      if (pre->val == cur->val)
      {
        ListNode *deleteNode = cur;
        pre->next = cur->next;
        delete deleteNode;
        cur = pre->next;
      }
      else
      {
        pre = cur;
        cur = cur->next;
      }
    }

    ListNode *retNode = dummyHead->next;
    delete dummyHead;

    return retNode;
  }
};