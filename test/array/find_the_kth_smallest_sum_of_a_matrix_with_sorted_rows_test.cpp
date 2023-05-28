#include <array/find_the_kth_smallest_sum_of_a_matrix_with_sorted_rows.cpp>

TEST(有序矩阵中的第k个最小数组和, kthSmallest) {
  Solution solution;
  // 示例 1：
  // 输入：mat = [[1,3,11],[2,4,6]], k = 5
  // 输出：7
  // 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
  // [1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。
  // 示例 2：
  // 输入：mat = [[1,3,11],[2,4,6]], k = 9
  // 输出：17
  vector<vector<int>> mat{{1, 3, 11}, {2, 4, 6}};
  int k = 5;
  EXPECT_EQ(solution.kthSmallest(mat, k), 7);

  // 示例 3：
  // 输入：mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
  // 输出：9
  // 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
  // [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7
  // 个的和是 9 。
  mat = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
  k = 7;
  EXPECT_EQ(solution.kthSmallest(mat, k), 9);

  // 示例 4：
  // 输入：mat = [[1,1,10],[2,2,9]], k = 7
  // 输出：12
  mat = {{1, 1, 10}, {2, 2, 9}};
  k = 7;
  EXPECT_EQ(solution.kthSmallest(mat, k), 12);
}
