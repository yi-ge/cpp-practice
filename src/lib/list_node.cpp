#include <list_node.hpp>

// 创建链表，输入数组和数组长度，返回链表头指针
ListNode *createLinkedList(int arr[], int n)
{
  if (n == 0)
    return nullptr;

  ListNode *head = new ListNode(arr[0]);

  ListNode *curNode = head;
  for (int i = 1; i < n; i++)
  {
    curNode->next = new ListNode(arr[i]);
    curNode = curNode->next;
  }
  return head;
}

// 将链表转换为字符串输出
string listNodeToString(ListNode *head)
{
  string str = "";
  ListNode *curNode = head;
  while (curNode != nullptr)
  {
    str.append(to_string(curNode->val));
    str.append(" -> ");
    curNode = curNode->next;
  }
  str.append("NULL");
  return str;
}

// 输出链表
void printLinkedList(ListNode *head)
{
  ListNode *curNode = head;
  while (curNode != nullptr)
  {
    cout << curNode->val << " -> ";
    curNode = curNode->next;
  }
  cout << "NULL" << endl;
}

// 删除链表
void deleteLinkedList(ListNode *head)
{
  ListNode *curNode = head;
  while (curNode != nullptr)
  {
    ListNode *delNode = curNode;
    curNode = curNode->next;
    delete delNode;
  }
  return;
}