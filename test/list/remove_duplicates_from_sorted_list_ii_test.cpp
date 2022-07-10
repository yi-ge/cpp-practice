#include <list/remove_duplicates_from_sorted_list_ii.cpp>

TEST(删除排序链表中的重复元素2, deleteDuplicates2)
{
  // 示例 1：
  // 输入：head = [1,2,3,3,4,4,5]
  // 输出：[1,2,5]
  Solution solution;
  int arr[] = {1, 2, 3, 3, 4, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  int arr2[] = {1, 2, 5};
  int n2 = sizeof(arr2) / sizeof(int);
  ListNode *head2 = createLinkedList(arr2, n2);
  ListNode *outHead = solution.deleteDuplicates2(head);
  EXPECT_STREQ(listNodeToString(outHead).c_str(), listNodeToString(head2).c_str());
  deleteLinkedList(outHead);
  deleteLinkedList(head2);

  // 示例 2：
  // 输入：head = [1,1,1,2,3]
  // 输出：[2,3]
  int arr3[] = {1, 1, 1, 2, 3};
  int n3 = sizeof(arr3) / sizeof(int);
  ListNode *head3 = createLinkedList(arr3, n3);
  int arr4[] = {2, 3};
  int n4 = sizeof(arr4) / sizeof(int);
  ListNode *head4 = createLinkedList(arr4, n4);
  ListNode *outHead2 = solution.deleteDuplicates2(head3);
  EXPECT_STREQ(listNodeToString(outHead2).c_str(), listNodeToString(head4).c_str());
  deleteLinkedList(outHead2);
  deleteLinkedList(head4);

  int arr5[] = {1, 1};
  int n5 = sizeof(arr5) / sizeof(int);
  ListNode *head5 = createLinkedList(arr5, n5);
  int arr6[] = {};
  int n6 = sizeof(arr6) / sizeof(int);
  ListNode *head6 = createLinkedList(arr6, n6);
  ListNode *outHead3 = solution.deleteDuplicates2(head5);
  EXPECT_STREQ(listNodeToString(outHead3).c_str(), listNodeToString(head6).c_str());
  deleteLinkedList(outHead3);
  deleteLinkedList(head6);
}
