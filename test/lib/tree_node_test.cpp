#include <headers.hpp>

TEST(树lib, printTree)
{
  int n = 15;
  vector<TreeNode *> nodes(n);

  for (int i = n - 1; i >= 0; --i)
  {
    TreeNode *node = new TreeNode(i + 1);
    int leftId = i * 2 + 1;
    int rightId = leftId + 1;
    node->left = leftId < n ? nodes[leftId] : nullptr;
    node->right = rightId < n ? nodes[rightId] : nullptr;
    nodes[i] = node;
  }

  printTree(nodes[0]);

  for (int i = 0; i < n; ++i)
  {
    delete nodes[i];
    nodes[i] = nullptr;
  }
}

TEST(树lib, createTree)
{
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  vector<int> treeVec = {1, 2, 3};

  TreeNode *tree = createTree(treeVec);

  printTree(tree);
  string treeStr = treeToString(tree);
  string rootStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), rootStr.c_str());

  delete tree;
  delete root;
}

TEST(树lib, createTreeCycle)
{
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  vector<int> treeVec = {1, 2, 3};

  TreeNode *tree = createTreeCycle(treeVec);

  printTree(tree);
  string treeStr = treeToString(tree);
  string rootStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), rootStr.c_str());

  delete tree;
  delete root;
}

TEST(树lib, treeToVec)
{
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
}

TEST(树lib, treeToString)
{
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  string treeStr = treeToString(root);

  EXPECT_STREQ(treeStr.c_str(), "[1,2,3]");

  delete root;
}

TEST(树lib, stringToTree)
{
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *root = new TreeNode(1, left, right);

  TreeNode *tree = stringToTree("[1,2,3]");
  vector<int> treeResVec = treeToVec(tree);

  vector<int> treeVec = {1, 2, 3};

  EXPECT_THAT(treeVec, ::testing::ContainerEq(treeResVec));

  delete tree;
  delete root;
}