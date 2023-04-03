#include <array/previous_permutation_with_one_swap.cpp>

TEST(交换一次的先前排列, prevPermOpt1) {
  // 示例 1：
  // 输入：arr = [3,2,1]
  // 输出：[3,1,2]
  // 解释：交换 2 和 1
  std::vector<int> arr1 = {3, 2, 1};
  std::vector<int> exp1 = {3, 1, 2};
  Solution solution1;
  EXPECT_EQ(solution1.prevPermOpt1(arr1), exp1);

  // 示例 2：
  // 输入：arr = [1,1,5]
  // 输出：[1,1,5]
  // 解释：已经是最小排列
  std::vector<int> arr2 = {1, 1, 5};
  std::vector<int> exp2 = {1, 1, 5};
  Solution solution2;
  EXPECT_EQ(solution2.prevPermOpt1(arr2), exp2);

  // 示例 3：
  // 输入：arr = [1,9,4,6,7]
  // 输出：[1,7,4,6,9]
  // 解释：交换 9 和 7
  std::vector<int> arr3 = {1, 9, 4, 6, 7};
  std::vector<int> exp3 = {1, 7, 4, 6, 9};
  Solution solution3;
  EXPECT_EQ(solution3.prevPermOpt1(arr3), exp3);

  // 示例 4：
  std::vector<int> arr4 = {3, 1, 1, 3};
  std::vector<int> exp4 = {1, 3, 1, 3};
  Solution solution4;
  EXPECT_EQ(solution4.prevPermOpt1(arr4), exp4);

  // 边界情况1：空数组
  std::vector<int> arr7 = {};
  std::vector<int> exp7 = {};
  Solution solution7;
  EXPECT_EQ(solution7.prevPermOpt1(arr7), exp7);

  // 边界情况2：只有一个元素的数组
  std::vector<int> arr5 = {1};
  std::vector<int> exp5 = {1};
  Solution solution5;
  EXPECT_EQ(solution5.prevPermOpt1(arr5), exp5);

  // 性能测试：长度较长的数组
  std::vector<int> arr6 = {4,  3, 2,  1,  8,  7,  6,  5,  12, 11,
                           10, 9, 16, 15, 14, 13, 20, 19, 18, 17};
  std::vector<int> exp6 = {4,  3, 2,  1,  8,  7,  6,  5,  12, 11,
                           10, 9, 16, 15, 14, 13, 20, 19, 17, 18};
  Solution solution6;
  EXPECT_EQ(solution6.prevPermOpt1(arr6), exp6);
}
