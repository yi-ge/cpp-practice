#include <list/insert_greatest_common_divisors_in_linked_list.cpp>

TEST(在链表中插入最大公约数, ListNode) {
  Solution solution;
  // 示例 1：
  // 输入：head = [18,6,10,3]
  // 输出：[18,6,6,2,10,1,3]
  // 解释：第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
  // - 18 和 6 的最大公约数为 6 ，插入第一和第二个结点之间。
  // - 6 和 10 的最大公约数为 2 ，插入第二和第三个结点之间。
  // - 10 和 3 的最大公约数为 1 ，插入第三和第四个结点之间。
  // 所有相邻结点之间都插入完毕，返回链表。
  int list[] = {18, 6, 10, 3};
  int n = sizeof(list) / sizeof(int);
  ListNode *head = createLinkedList(list, n);
  ListNode *result = solution.insertGreatestCommonDivisors(head);
  int expected[] = {18, 6, 6, 2, 10, 1, 3};
  int m = sizeof(expected) / sizeof(int);
  ListNode *expected_result = createLinkedList(expected, m);
  EXPECT_STREQ(listNodeToString(head).c_str(),
               listNodeToString(expected_result).c_str());
  deleteLinkedList(head);
  deleteLinkedList(expected_result);

  // 示例 2：
  // 输入：head = [7]
  // 输出：[7]
  // 解释：第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
  // 没有相邻结点，所以返回初始链表。
  int list2[] = {7};
  int n2 = sizeof(list2) / sizeof(int);
  ListNode *head2 = createLinkedList(list2, n2);
  ListNode *result2 = solution.insertGreatestCommonDivisors(head2);
  int expected2[] = {7};
  int m2 = sizeof(expected2) / sizeof(int);
  ListNode *expected_result2 = createLinkedList(expected2, m2);
  EXPECT_STREQ(listNodeToString(head2).c_str(),
               listNodeToString(expected_result2).c_str());
  deleteLinkedList(head2);
  deleteLinkedList(expected_result2);
}
