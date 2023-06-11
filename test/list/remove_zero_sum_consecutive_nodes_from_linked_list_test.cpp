#include <list/remove_zero_sum_consecutive_nodes_from_linked_list.cpp>

TEST(从链表中删去总和值为零的连续节点, ListNode) {
  Solution solution;
  // 示例 1：
  // 输入：head = [1,2,-3,3,1]
  // 输出：[3,1]
  // 提示：答案 [1,2,1] 也是正确的。
  int arr[] = {1, 2, -3, 3, 1};
  int n = sizeof(arr) / sizeof(int);
  ListNode *head = createLinkedList(arr, n);
  int result[] = {3, 1};
  int resultLength = sizeof(result) / sizeof(int);
  ListNode *resultHead = createLinkedList(result, resultLength);
  ListNode *outHead = solution.removeZeroSumSublists(head);
  EXPECT_STREQ(listNodeToString(outHead).c_str(),
               listNodeToString(resultHead).c_str());

  // 示例 2：
  // 输入：head = [1,2,3,-3,4]
  // 输出：[1,2,4]
  int arr2[] = {1, 2, 3, -3, 4};
  int n2 = sizeof(arr2) / sizeof(int);
  ListNode *head2 = createLinkedList(arr2, n2);
  int result2[] = {1, 2, 4};
  int resultLength2 = sizeof(result2) / sizeof(int);
  ListNode *resultHead2 = createLinkedList(result2, resultLength2);
  ListNode *outHead2 = solution.removeZeroSumSublists(head2);
  EXPECT_STREQ(listNodeToString(outHead2).c_str(),
               listNodeToString(resultHead2).c_str());

  // 示例 3：
  // 输入：head = [1,2,3,-3,-2]
  // 输出：[1]
  int arr3[] = {1, 2, 3, -3, -2};
  int n3 = sizeof(arr3) / sizeof(int);
  ListNode *head3 = createLinkedList(arr3, n3);
  int result3[] = {1};
  int resultLength3 = sizeof(result3) / sizeof(int);
  ListNode *resultHead3 = createLinkedList(result3, resultLength3);
  ListNode *outHead3 = solution.removeZeroSumSublists(head3);
  EXPECT_STREQ(listNodeToString(outHead3).c_str(),
               listNodeToString(resultHead3).c_str());

  deleteLinkedList(outHead);
  deleteLinkedList(resultHead);
  deleteLinkedList(outHead2);
  deleteLinkedList(resultHead2);
  deleteLinkedList(outHead3);
  deleteLinkedList(resultHead3);
}
