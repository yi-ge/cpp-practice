#include "list_node.hpp"
#include <sort/merge_two_sorted_lists.cpp>

TEST(合并两个有序链表, ListNode) {
  // 示例 1：
  // 输入：l1 = [1,2,4], l2 = [1,3,4]
  // 输出：[1,1,2,3,4,4]
  Solution solution;
  int arr[] = {1, 2, 4};
  int n = sizeof(arr) / sizeof(int);
  ListNode *l1 = createLinkedList(arr, n);
  int arr2[] = {1, 3, 4};
  int n2 = sizeof(arr2) / sizeof(int);
  ListNode *l2 = createLinkedList(arr2, n2);
  int arr3[] = {1, 1, 2, 3, 4, 4};
  int n3 = sizeof(arr3) / sizeof(int);
  ListNode *res = createLinkedList(arr3, n3);
  EXPECT_EQ(listNodeToString(solution.mergeTwoLists(l1, l2)),
            listNodeToString(res));

  // 示例 2：
  // 输入：l1 = [], l2 = []
  // 输出：[]
  EXPECT_EQ(solution.mergeTwoLists(nullptr, nullptr), nullptr);

  // 示例 3：
  // 输入：l1 = [], l2 = [0]
  // 输出：[0]
  int arr31[] = {0};
  int n31 = sizeof(arr31) / sizeof(int);
  ListNode *l32 = createLinkedList(arr31, n31);
  EXPECT_EQ(listNodeToString(solution.mergeTwoLists(nullptr, l32)),
            listNodeToString(l32));

  EXPECT_EQ(listNodeToString(solution.mergeTwoLists(l32, nullptr)),
            listNodeToString(l32));
}
