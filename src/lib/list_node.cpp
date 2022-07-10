#include <list_node.hpp>

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
