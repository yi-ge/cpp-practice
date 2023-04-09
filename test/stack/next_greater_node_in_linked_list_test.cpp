#include <stack/next_greater_node_in_linked_list.cpp>

TEST(链表中的下一个更大节点, ListNode) {
  // 示例 1：
  // 输入：head = [2,1,5]
  // 输出：[5,5,0]
  Solution solution;
  ListNode *head = new ListNode(2);
  head->next = new ListNode(1);
  head->next->next = new ListNode(5);
  vector<int> result = solution.nextLargerNodes(head);
  vector<int> expect = {5, 5, 0};
  EXPECT_EQ(result, expect);

  // 示例 2：
  // 输入：head = [2,7,4,3,5]
  // 输出：[7,0,5,5,0]
  head = new ListNode(2);
  head->next = new ListNode(7);
  head->next->next = new ListNode(4);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(5);
  result = solution.nextLargerNodes(head);
  expect = {7, 0, 5, 5, 0};
  EXPECT_EQ(result, expect);
}
