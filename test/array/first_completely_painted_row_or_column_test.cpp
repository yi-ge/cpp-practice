#include <array/first_completely_painted_row_or_column.cpp>

TEST(找出叠涂元素, firstCompleteIndex) {
  Solution solution;
  // 示例 1：
  // 输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
  // 输出：2
  // 解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
  vector<int> arr1 = {1, 3, 4, 2};
  vector<vector<int>> mat1 = {{1, 4}, {2, 3}};
  EXPECT_EQ(solution.firstCompleteIndex(arr1, mat1), 2);

  // 示例 2：
  // 输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
  // 输出：3
  // 解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
  vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
  vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
  EXPECT_EQ(solution.firstCompleteIndex(arr2, mat2), 3);
}
