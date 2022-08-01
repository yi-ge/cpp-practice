#include <tree_node.hpp>
#include <tree_printer.hpp>
#include <queue>

void printTree(TreeNode *root)
{
  tp::TreePrinter<TreeNode> printer(root);
  printer.print();
}

TreeNode *createTree(vector<int> &nodes, const int index)
{
  TreeNode *root = nullptr;

  if (index < nodes.size() && nodes[index] != NULL)
  {
    root = new TreeNode(nodes[index]);
    root->left = createTree(nodes, index * 2 + 1);
    root->right = createTree(nodes, index * 2 + 2);
  }

  return root;
}

TreeNode *createTree(vector<int> &nodes)
{
  return createTree(nodes, 0);
}

TreeNode *createTreeCycle(vector<int> &nodes)
{
  vector<TreeNode *> vecTree(nodes.size(), NULL);
  TreeNode *root = NULL;
  for (int i = 0; i < nodes.size(); i++)
  {
    TreeNode *node = NULL;
    if (nodes[i] != -1)
      node = new TreeNode(nodes[i]);
    vecTree[i] = node;
    if (i == 0)
      root = node;
  }
  for (int i = 0; i * 2 + 2 < nodes.size(); i++)
  {
    if (vecTree[i] != NULL)
    {
      vecTree[i]->left = vecTree[i * 2 + 1];
      vecTree[i]->right = vecTree[i * 2 + 2];
    }
  }
  return root;
}

vector<int> treeToVec(TreeNode *root)
{
  vector<int> res;
  queue<TreeNode *> que;
  if (root != NULL)
    que.push(root);
  while (!que.empty())
  {
    TreeNode *node = que.front();
    if (node != NULL)
      res.push_back(node->val);
    else
      res.push_back(NULL);

    if (node->left != NULL)
      que.push(node->left);

    if (node->right != NULL)
      que.push(node->right);

    que.pop();
  }

  return res;
}

string treeToString(TreeNode *root)
{
  string res = "[";
  queue<TreeNode *> que;
  if (root != NULL)
    que.push(root);
  while (!que.empty())
  {
    TreeNode *node = que.front();
    if (node != NULL)
    {
      res.append(to_string(node->val));
      res.append(",");
    }
    else
      res.append("null");

    if (node->left != NULL)
      que.push(node->left);

    if (node->right != NULL)
      que.push(node->right);

    que.pop();
  }
  res.replace(res.rfind(","), 1, "");
  res.append("]");
  return res;
}

TreeNode *stringToTree(string treeStr)
{
  vector<int> nodes;
  string delim = ",";
  string strs = treeStr + delim; // 扩展字符串以方便检索最后一个分隔出的字符串
  size_t pos;
  size_t size = strs.size();

  for (int i = 1; i < size - 1; ++i)
  {
    pos = strs.find(delim, i); // pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
    if (pos < size)
    {                                     //如果查找到，如果没有查找到分隔符，pos为string::npos
      string s = strs.substr(i, pos - i); // 从i开始长度为pos-i的子字符串
      if (s == "null")
      {
        nodes.push_back(NULL);
      }
      else
      {
        nodes.push_back(atoi(s.c_str()));
      }
      i = pos + delim.size() - 1;
    }
  }

  TreeNode *root = createTreeCycle(nodes);
  return root;
}
