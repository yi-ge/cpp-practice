#include <headers.hpp>

TEST(链表lib, createLinkedList) {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  EXPECT_EQ(head->val, 1);
  EXPECT_EQ(head->next->val, 2);
  EXPECT_EQ(head->next->next->val, 3);
  EXPECT_EQ(head->next->next->next->val, 4);
  EXPECT_TRUE(head->next->next->next->next == nullptr);
  deleteLinkedList(head);
}

TEST(链表lib, listNodeToString) {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  EXPECT_STREQ(listNodeToString(head).c_str(), "1 -> 2 -> 3 -> 4 -> NULL");
  deleteLinkedList(head);
}

TEST(链表lib, printLinkedList) {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  // printLinkedList(head);
  EXPECT_STREQ(listNodeToString(head).c_str(), "1 -> 2 -> 3 -> 4 -> NULL");
  deleteLinkedList(head);
}

TEST(链表lib, deleteLinkedList) {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  deleteLinkedList(head);
}
