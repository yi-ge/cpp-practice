#include <cstdio>
#include <queue>
#include <tree_node.hpp>
#include <tree_printer.hpp>

// 打印二叉树
void printTree(TreeNode *root) {
  tp::TreePrinter<TreeNode> printer(root);
  printer.print();
}

// 根据vector创建二叉树
TreeNode *createTree(vector<int> &nodes) {
  if (nodes.empty())
    return nullptr;

  TreeNode *root = new TreeNode(nodes[0]);
  queue<TreeNode *>
      q; // 使用一个额外的 vector 让 createTree 函数支持省略连续 NULL 节点的功能
  q.push(root);

  // 遍历vector，逐层创建二叉树
  for (size_t i = 1; i < nodes.size();) {
    TreeNode *node = q.front();
    q.pop();

    // 如果节点不为空，则创建左子节点
    if (nodes[i] != NULL) {
      node->left = new TreeNode(nodes[i]);
      q.push(node->left);
    }
    ++i;

    // 如果节点不为空，则创建右子节点
    if (i < nodes.size() && nodes[i] != NULL) {
      node->right = new TreeNode(nodes[i]);
      q.push(node->right);
    }
    ++i;
  }

  return root;
} // LCOV_EXCL_LINE

// 不支持省略连续 NULL 节点
// TreeNode *createTree(vector<int> &nodes, const int index) {
//   TreeNode *root = nullptr;
//   // printf("%d - %d\n", nodes.size(), index);
//   if (index < nodes.size() && nodes[index] != NULL) {
//     root = new TreeNode(nodes[index]);
//     root->left = createTree(nodes, index * 2 + 1);
//     root->right = createTree(nodes, index * 2 + 2);
//   }

//   return root;
// } // LCOV_EXCL_LINE

// TreeNode *createTree(vector<int> &nodes) { return createTree(nodes, 0); }

// 错误写法：
// TreeNode *createTreeRecursive(const vector<int> &nodes, int index) {
//   if (index >= nodes.size() || nodes[index] == NULL) {
//     return nullptr;
//   }

//   TreeNode *node = new TreeNode(nodes[index]);
//   node->left = createTreeRecursive(nodes, 2 * index + 1);
//   node->right = createTreeRecursive(nodes, 2 * index + 2);

//   return node;
// } // LCOV_EXCL_LINE

// TreeNode *createTree(const vector<int> &nodes) {
//   return createTreeRecursive(nodes, 0);
// }

// 非递归写法：
// // Helper function to create a binary tree from a given vector<int>
// TreeNode *createTree(vector<int> &nodes) {
//   if (nodes.empty() || nodes[0] == NULL) {
//     return nullptr;
//   }

//   TreeNode *root = new TreeNode(nodes[0]);
//   std::queue<TreeNode *> q;
//   q.push(root);

//   size_t i = 1;
//   while (!q.empty() && i < nodes.size()) {
//     TreeNode *current = q.front();
//     q.pop();

//     if (nodes[i] != NULL) {
//       current->left = new TreeNode(nodes[i]);
//       q.push(current->left);
//     }
//     i++;

//     if (i < nodes.size() && nodes[i] != NULL) {
//       current->right = new TreeNode(nodes[i]);
//       q.push(current->right);
//     }
//     i++;
//   }

//   return root;
// }

TreeNode *createTreeCycle(vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }

  int i, size = values.size();
  TreeNode *root = new TreeNode(values[0]);
  queue<TreeNode *> nodes;
  nodes.push(root);

  TreeNode *current = root;
  TreeNode *node;

  for (i = 1; i < size; ++i) {
    node = new TreeNode(values[i]);
    nodes.push(node);

    // 如果是奇数，则该节点为左子节点
    if (i % 2 == 1) {
      current = nodes.front();
      nodes.pop();
      current->left = node;
    } else { // 否则为右子节点
      current->right = node;
    }
  }

  return root;
}

// 将二叉树转化为vector
vector<int> treeToVec(TreeNode *root) {
  vector<int> res;
  queue<TreeNode *> que;
  if (root != NULL)
    que.push(root);
  while (!que.empty()) {
    TreeNode *node = que.front();
    if (node->val != NULL)
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

// 将二叉树转化为字符串
string treeToString(TreeNode *root) {
  string res = "[";
  queue<TreeNode *> que;
  if (root != NULL)
    que.push(root);
  while (!que.empty()) {
    TreeNode *node = que.front();
    if (node->val != NULL) {
      res.append(to_string(node->val));
      res.append(",");
    } else {
      res.append("null");
      res.append(",");
    }

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

// 将字符串转化为二叉树
TreeNode *stringToTree(string treeStr) {
  vector<int> nodes;
  string delim = ",";
  string strs = treeStr + delim; // 扩展字符串以方便检索最后一个分隔出的字符串
  size_t pos;
  size_t size = strs.size();

  for (int i = 1; i < size - 1; ++i) {
    pos = strs.find(
        delim,
        i); // pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
    if (pos < size) { // 如果查找到，如果没有查找到分隔符，pos为string::npos
      string s = strs.substr(i, pos - i); // 从i开始长度为pos-i的子字符串
      if (s == "null]" || s == "null,") { // 如果字符串为"null"，则节点为空
        nodes.push_back(NULL);
      } else {
        nodes.push_back(atoi(s.c_str()));
      }
      i = pos + delim.size() - 1;
    }
  }

  TreeNode *root = createTreeCycle(nodes);
  return root;
}

// 判断两个二叉树是否相等
bool isTreeEqual(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr && t2 == nullptr)
    return true;
  if (t1 == nullptr || t2 == nullptr)
    return false;

  return (t1->val == t2->val) && isTreeEqual(t1->left, t2->left) &&
         isTreeEqual(t1->right, t2->right);
}