// 在链表中插入最大公约数
// https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list
// INLINE  ../../images/list/insert_greatest_common_divisors_in_linked_list.jpeg

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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    for (auto cur = head; cur->next; cur = cur->next->next) {
      cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
    }
    return head;
  }
};