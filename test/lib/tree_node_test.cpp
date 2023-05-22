#include "tree_node.hpp"
#include <gtest/gtest.h>
#include <headers.hpp>

TEST(树lib, printTree) {
  int n = 15;
  vector<TreeNode *> nodes(n);

  for (int i = n - 1; i >= 0; --i) {
    TreeNode *node = new TreeNode(i + 1);
    int leftId = i * 2 + 1;
    int rightId = leftId + 1;
    node->left = leftId < n ? nodes[leftId] : nullptr;
    node->right = rightId < n ? nodes[rightId] : nullptr;
    nodes[i] = node;
  }

  printTree(nodes[0]);

  for (int i = 0; i < n; ++i) {
    delete nodes[i];
    nodes[i] = nullptr;
  }
}

TEST(树lib, createTree) {
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  vector<int> treeVec = {1, 2, 3};

  TreeNode *tree = createTree(treeVec);

  printTree(tree);
  string treeStr = treeToString(tree);
  string rootStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), rootStr.c_str());

  vector<int> treeVec2 = {};
  EXPECT_EQ(createTree(treeVec2), nullptr);

  vector<int> treeVec4 = {1, 2, 3, 4, NULL, NULL, 7, 8, 9, NULL, 14};
  vector<int> treeVec5 = {1, 2,    3,    4,    NULL, NULL, 7, 8,
                          9, NULL, NULL, NULL, NULL, NULL, 14};

  treeStr = treeToString(createTree(treeVec4));
  rootStr = treeToString(createTree(treeVec5));
  EXPECT_STREQ(treeStr.c_str(), rootStr.c_str());

  delete tree;
  delete root;
}

TEST(树lib, createTreeCycle) {
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  vector<int> treeVec = {1, 2, 3};

  TreeNode *tree = createTreeCycle(treeVec);

  printTree(tree);
  string treeStr = treeToString(tree);
  string rootStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), rootStr.c_str());

  vector<int> treeVec2 = {};
  EXPECT_EQ(createTreeCycle(treeVec2), nullptr);

  delete tree;
  delete root;
}

TEST(树lib, treeToVec) {
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  vector<int> treeVec = {1, 2, 3};
  vector<int> tree = treeToVec(root);

  EXPECT_THAT(tree, ::testing::ContainerEq(treeVec));

  delete root;

  TreeNode *node = new TreeNode(NULL);
  vector<int> res = {NULL};
  EXPECT_THAT(treeToVec(node), ::testing::ContainerEq(res));
  delete node;

  TreeNode *node2 = new TreeNode(2, new TreeNode(NULL));
  vector<int> res2 = {2, NULL};
  EXPECT_THAT(treeToVec(node2), ::testing::ContainerEq(res2));
  delete node2;
}

TEST(树lib, treeToString) {
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  string treeStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), "[1,2,3]");

  TreeNode *left2 = new TreeNode();
  TreeNode *root2 = new TreeNode(1, left2);
  string treeStr2 = treeToString(root2);
  EXPECT_STREQ(treeStr2.c_str(), "[1,null]");

  delete root;
}

TEST(树lib, stringToTree) {
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  TreeNode *tree = stringToTree("[1,2,3]");
  vector<int> treeResVec = treeToVec(tree);

  vector<int> treeVec = {1, 2, 3};

  EXPECT_THAT(treeVec, ::testing::ContainerEq(treeResVec));

  delete tree;
  delete root;

  TreeNode *tree2 = stringToTree("[1,null]");
  EXPECT_EQ(tree2->left->val, NULL);
  vector<int> treeResVec2 = treeToVec(tree2);
  vector<int> treeVec2 = {1, NULL};

  EXPECT_THAT(treeResVec2, ::testing::ContainerEq(treeVec2));

  delete tree2;

  TreeNode *tree3 = stringToTree("[1,null,2]");
  EXPECT_EQ(tree3->left->val, NULL);
  EXPECT_EQ(tree3->right->val, 2);
  vector<int> treeResVec3 = treeToVec(tree3);
  vector<int> treeVec3 = {1, NULL, 2};

  EXPECT_THAT(treeResVec3, ::testing::ContainerEq(treeVec3));

  delete tree3;
}

TEST(树lib, isTreeEqual) {
  // Test Case 1: Two identical trees
  vector<int> treeNodes1 = {1, 2,   3,   4,  -99, -99, 7, 8,
                            9, -99, -99, 12, 13,  -99, 14};
  TreeNode *tree1 = createTree(treeNodes1);
  TreeNode *tree2 = createTree(treeNodes1);
  EXPECT_TRUE(isTreeEqual(tree1, tree2));

  // Test Case 2: Different root values
  vector<int> treeNodes2 = {5, 2,   3,   4,  -99, -99, 7, 8,
                            9, -99, -99, 12, 13,  -99, 14};
  TreeNode *tree3 = createTree(treeNodes2);
  EXPECT_FALSE(isTreeEqual(tree1, tree3));

  // Test Case 3: Different subtrees
  vector<int> treeNodes3 = {1,  2,   3,   4,  -99, -99, 7, 8,
                            10, -99, -99, 12, 13,  -99, 14};
  TreeNode *tree4 = createTree(treeNodes3);
  EXPECT_FALSE(isTreeEqual(tree1, tree4));

  // Test Case 4: One tree is nullptr
  TreeNode *tree5 = nullptr;
  EXPECT_FALSE(isTreeEqual(tree1, tree5));
  EXPECT_FALSE(isTreeEqual(tree5, tree1));

  // Test Case 5: Both trees are nullptr
  TreeNode *tree6 = nullptr;
  EXPECT_TRUE(isTreeEqual(tree5, tree6));

  // Test Case 6: 存在省略情况的两棵树
  vector<int> treeVec1 = {1, 2, 3, 4, NULL, NULL, 7, 8, 9, NULL, 14};
  vector<int> treeVec2 = {1, 2,    3,    4,    NULL, NULL, 7, 8,
                          9, NULL, NULL, NULL, NULL, NULL, 14};
  TreeNode *tree7 = createTree(treeVec1);
  TreeNode *tree8 = createTree(treeVec2);
  printTree(tree7);
  printTree(tree8);
  EXPECT_FALSE(isTreeEqual(tree7, tree8));
}
