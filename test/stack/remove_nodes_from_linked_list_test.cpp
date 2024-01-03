#include <stack/remove_nodes_from_linked_list.cpp>

TEST(从链表中移除节点, ListNode) {
  Solution solution;
  // 示例 1：
  // 输入：head = [5,2,13,3,8]
  // 输出：[13,8]
  // 解释：需要移除的节点是 5 ，2 和 3 。
  // - 节点 13 在节点 5 右侧。
  // - 节点 13 在节点 2 右侧。
  // - 节点 8 在节点 3 右侧。
  ListNode *head = new ListNode(5);
  head->next = new ListNode(2);
  head->next->next = new ListNode(13);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(8);
  ListNode *result = solution.removeNodes(head);
  EXPECT_EQ(result->val, 13);
  EXPECT_EQ(result->next->val, 8);
  EXPECT_EQ(result->next->next, nullptr);

  // 示例 2：
  // 输入：head = [1,1,1,1]
  // 输出：[1,1,1,1]
  // 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
  head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(1);
  result = solution.removeNodes(head);
  EXPECT_EQ(result->val, 1);
  EXPECT_EQ(result->next->val, 1);
  EXPECT_EQ(result->next->next->val, 1);
  EXPECT_EQ(result->next->next->next->val, 1);
  EXPECT_EQ(result->next->next->next->next, nullptr);
}
