#include <tree/kth_ancestor_of_a_tree_node.cpp>

TEST(树节点的第K个祖先, TreeAncestor) {
  // 示例 1：
  // 输入：
  // ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
  // [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

  // 输出：
  // [null,1,0,-1]

  // 解释：
  // TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

  // treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
  // treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
  // treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
  int n = 7;
  vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  TreeAncestor *treeAncestor = new TreeAncestor(n, parent);
  EXPECT_EQ(treeAncestor->getKthAncestor(3, 1), 1);
  EXPECT_EQ(treeAncestor->getKthAncestor(5, 2), 0);
  EXPECT_EQ(treeAncestor->getKthAncestor(6, 3), -1);
}
