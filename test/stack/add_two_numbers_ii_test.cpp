#include <stack/add_two_numbers_ii.cpp>

TEST(两数相加II, ListNode) {
  Solution solution;
  // 示例1：
  // 输入：l1 = [7,2,4,3], l2 = [5,6,4]
  // 输出：[7,8,0,7]
  vector<int> l1 = {7, 2, 4, 3};
  vector<int> l2 = {5, 6, 4};
  ListNode *l1_head = new ListNode(l1[0]);
  ListNode *l2_head = new ListNode(l2[0]);
  ListNode *l1_tail = l1_head;
  ListNode *l2_tail = l2_head;
  for (int i = 1; i < l1.size(); i++) {
    l1_tail->next = new ListNode(l1[i]);
    l1_tail = l1_tail->next;
  }
  for (int i = 1; i < l2.size(); i++) {
    l2_tail->next = new ListNode(l2[i]);
    l2_tail = l2_tail->next;
  }
  ListNode *result = solution.addTwoNumbers(l1_head, l2_head);
  EXPECT_EQ(result->val, 7);
  EXPECT_EQ(result->next->val, 8);
  EXPECT_EQ(result->next->next->val, 0);
  EXPECT_EQ(result->next->next->next->val, 7);

  // 示例2：
  // 输入：l1 = [2,4,3], l2 = [5,6,4]
  // 输出：[8,0,7]
  l1 = {2, 4, 3};
  l2 = {5, 6, 4};
  l1_head = new ListNode(l1[0]);
  l2_head = new ListNode(l2[0]);
  l1_tail = l1_head;
  l2_tail = l2_head;
  for (int i = 1; i < l1.size(); i++) {
    l1_tail->next = new ListNode(l1[i]);
    l1_tail = l1_tail->next;
  }
  for (int i = 1; i < l2.size(); i++) {
    l2_tail->next = new ListNode(l2[i]);
    l2_tail = l2_tail->next;
  }
  result = solution.addTwoNumbers(l1_head, l2_head);
  EXPECT_EQ(result->val, 8);
  EXPECT_EQ(result->next->val, 0);
  EXPECT_EQ(result->next->next->val, 7);

  // 示例3：
  // 输入：l1 = [0], l2 = [0]
  // 输出：[0]
  l1 = {0};
  l2 = {0};
  l1_head = new ListNode(l1[0]);
  l2_head = new ListNode(l2[0]);
  l1_tail = l1_head;
  l2_tail = l2_head;
  for (int i = 1; i < l1.size(); i++) {
    l1_tail->next = new ListNode(l1[i]);
    l1_tail = l1_tail->next;
  }
  for (int i = 1; i < l2.size(); i++) {
    l2_tail->next = new ListNode(l2[i]);
    l2_tail = l2_tail->next;
  }
  result = solution.addTwoNumbers(l1_head, l2_head);
  EXPECT_EQ(result->val, 0);
}
