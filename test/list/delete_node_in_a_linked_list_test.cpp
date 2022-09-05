#include <list/delete_node_in_a_linked_list.cpp>

TEST(删除链表中的节点, deleteNode)
{
  // 示例 1：
  // 输入：head = [4,5,1,9], node = 5
  // 输出：[4,1,9]
  // 解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9
  Solution solution;
  int arr[] = {4, 5, 1, 9};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  ListNode *node = head->next;
  solution.deleteNode(node);
  int arr2[] = {4, 1, 9};
  int n2 = sizeof(arr2) / sizeof(int);
  ListNode *head2 = createLinkedList(arr2, n2);
  EXPECT_STREQ(listNodeToString(head).c_str(), listNodeToString(head2).c_str());
  deleteLinkedList(head);
  deleteLinkedList(head2);

  // 示例 2：
  // 输入：head = [4,5,1,9], node = 1
  // 输出：[4,5,9]
  // 解释：指定链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9
  int arr3[] = {4, 5, 1, 9};
  int n3 = sizeof(arr3) / sizeof(int);
  ListNode *head3 = createLinkedList(arr3, n3);
  ListNode *node2 = head3->next->next;
  solution.deleteNode(node2);
  int arr4[] = {4, 5, 9};
  int n4 = sizeof(arr4) / sizeof(int);
  ListNode *head4 = createLinkedList(arr4, n4);
  EXPECT_NO_THROW(solution.deleteNode(nullptr));
  EXPECT_STREQ(listNodeToString(head3).c_str(), listNodeToString(head4).c_str());
  deleteLinkedList(head3);
  deleteLinkedList(head4);

  int arr5[] = {4};
  int n5 = sizeof(arr5) / sizeof(int);
  ListNode *head5 = createLinkedList(arr5, n5);
  EXPECT_NO_THROW(solution.deleteNode(head5));
}
