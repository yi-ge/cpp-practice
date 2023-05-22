#include <sort/largest_values_from_labels.cpp>

TEST(受标签影响的最大值, largestValsFromLabels) {
  Solution solution;
  // 示例 1：
  // 输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit =
  // 1 输出：9 解释：选出的子集是第一项，第三项和第五项。
  vector<int> values = {5, 4, 3, 2, 1};
  vector<int> labels = {1, 1, 2, 2, 3};
  int numWanted = 3;
  int useLimit = 1;
  EXPECT_EQ(solution.largestValsFromLabels(values, labels, numWanted, useLimit),
            9);

  // 示例 2：
  // 输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit =
  // 2 输出：12 解释：选出的子集是第一项，第二项和第三项。
  values = {5, 4, 3, 2, 1};
  labels = {1, 3, 3, 3, 2};
  numWanted = 3;
  useLimit = 2;
  EXPECT_EQ(solution.largestValsFromLabels(values, labels, numWanted, useLimit),
            12);

  // 示例 3：
  // 输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit =
  // 1 输出：16 解释：选出的子集是第一项和第四项。
  values = {9, 8, 8, 7, 6};
  labels = {0, 0, 0, 1, 1};
  numWanted = 3;
  useLimit = 1;
  EXPECT_EQ(solution.largestValsFromLabels(values, labels, numWanted, useLimit),
            16);
}
