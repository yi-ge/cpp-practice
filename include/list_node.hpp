#pragma once
#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(int arr[], int n);

string listNodeToString(ListNode *head);

void printLinkedList(ListNode *head);

void deleteLinkedList(ListNode *head);