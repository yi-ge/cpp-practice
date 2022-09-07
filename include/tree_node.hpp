#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left) : val(x), left(left), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void printTree(TreeNode *root);

TreeNode *createTree(vector<int> &nodes);
TreeNode *createTree(vector<int> &nodes, const int index);

TreeNode *createTreeCycle(vector<int> &nodes);

vector<int> treeToVec(TreeNode *root);

string treeToString(TreeNode *node);

TreeNode *stringToTree(string treeStr);