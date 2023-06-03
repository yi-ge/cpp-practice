// 移除链表元素
// https://leetcode.cn/problems/remove-linked-list-elements/
// INLINE  ../../images/list/remove_linked_list_elements.jpeg
#include <headers.hpp>

class Solution {
public:
  //移除链表中值为val的元素
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(0); //创建虚拟头结点
    dummyHead->next = head; //虚拟头结点指向head
    ListNode *cur = dummyHead; //当前结点指针指向虚拟头结点
    while (cur->next != nullptr) { //当当前结点指针的下一结点不为空
      if (cur->next->val == val) { //判断下一结点的值是否等于给定的val
        ListNode *deleteNode = cur->next; //如果相等，创建一个指向下一结点的指针
        cur->next = cur->next->next; //当前结点的下一结点指向下一个结点，即跳过删除结点
        delete deleteNode; //释放删除结点的空间
      } else {
        cur = cur->next; //不相等则将当前结点指针后移一位
      }
    }

    ListNode *retNode = dummyHead->next; //返回虚拟头结点的下一结点
    delete dummyHead; //释放虚拟头结点的内存空间

    return retNode;
  } // LCOV_EXCL_LINE
};