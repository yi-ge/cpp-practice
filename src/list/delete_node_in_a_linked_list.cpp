// 删除链表中的节点
// https://leetcode.cn/problems/delete-node-in-a-linked-list/
// INLINE  ../../images/list/delete_node_in_a_linked_list.jpeg
#include <headers.hpp>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void deleteNode(ListNode *node) {
    // 如果节点为空，直接返回
    if (node == nullptr)
      return;

    // 如果节点的下一个节点为空，直接删除该节点
    if (node->next == nullptr) {
      delete node;
      node = nullptr;
      return;
    }
    // 将该节点的值设为下一个节点的值
    node->val = node->next->val;
    // 删除下一个节点
    ListNode *deleteNode = node->next;
    node->next = deleteNode->next;
    delete deleteNode;
    return;
  }
};