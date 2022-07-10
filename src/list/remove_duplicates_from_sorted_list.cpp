// 删除排序链表中的重复元素
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
// INLINE  ../images/list/remove_duplicates_from_sorted_list.jpeg
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
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
      if (cur->next->val == cur->val)
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

    return head;
  }
};