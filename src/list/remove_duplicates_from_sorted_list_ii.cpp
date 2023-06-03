// 删除排序链表中的重复元素 II
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
// INLINE  ../../images/list/remove_duplicates_from_sorted_list_ii.jpeg
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
  ListNode *deleteDuplicates2(ListNode *head) {
    ListNode *dummyHead = new ListNode(); // 创建虚拟头结点，方便链表的操作
    dummyHead->next = head;               // 将虚拟头结点指向 head
    ListNode *pre = dummyHead;            // pre 指向虚拟头结点
    ListNode *cur = head;                 // cur 指向 head
    int deletedVal;                       // 记录已删除的元素
    while (cur != nullptr &&
           cur->next != nullptr) { // 当 cur 不为空且 cur 的下一个结点不为空时
      if (cur->val == cur->next->val ||
          cur->val ==
              deletedVal) { // 如果当前结点的值等于下一个结点的值或者当前结点的值等于已删除的值
        deletedVal = cur->val; // 将已删除的值设为当前结点的值
        ListNode *deleteNode = cur; // 创建一个指向当前结点的指针
        pre->next = cur->next; // 将前一个结点的 next 指向当前结点的下一个结点
        delete deleteNode; // 删除当前结点
        cur = pre->next;   // 将当前结点移动到下一个结点
      } else {
        pre = cur;       // 将 pre 移动到当前结点
        cur = cur->next; // 将 cur 移动到下一个结点
      }
    }

    if (cur != nullptr &&
        cur->val ==
            deletedVal) { // 如果当前结点不为空且当前结点的值等于已删除的值
      ListNode *deleteNode = cur; // 创建一个指向当前结点的指针
      pre->next = nullptr;        // 将前一个结点的 next 设为 nullptr
      delete deleteNode;          // 删除当前结点
    }

    ListNode *retNode = dummyHead->next; // 将返回结点设为虚拟头结点的下一个结点
    delete dummyHead;                    // 删除虚拟头结点

    return retNode; // 返回结果
  }                 // LCOV_EXCL_LINE
};