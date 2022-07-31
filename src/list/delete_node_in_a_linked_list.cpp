// 删除链表中的节点
// https://leetcode.cn/problems/delete-node-in-a-linked-list/
// INLINE  ../images/list/delete_node_in_a_linked_list.jpeg
#include <headers.hpp>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    if (node == nullptr)
      return;

    if (node->next == nullptr)
    {
      delete node;
      node = nullptr;
      return;
    }
    node->val = node->next->val;
    ListNode *deleteNode = node->next;
    node->next = deleteNode->next;
    delete deleteNode;
    return;
  }
};