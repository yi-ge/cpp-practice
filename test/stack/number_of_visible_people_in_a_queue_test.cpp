#include <stack/number_of_visible_people_in_a_queue.cpp>

TEST(队列中可以看到的人数, canSeePersonsCount) {
  Solution solution;
  // 示例 1：
  // 输入：heights = [10,6,8,5,11,9]
  // 输出：[3,1,2,1,1,0]
  // 解释：
  // 第 0 个人能看到编号为 1 ，2 和 4 的人。
  // 第 1 个人能看到编号为 2 的人。
  // 第 2 个人能看到编号为 3 和 4 的人。
  // 第 3 个人能看到编号为 4 的人。
  // 第 4 个人能看到编号为 5 的人。
  // 第 5 个人谁也看不到因为他右边没人。
  vector heights = {10, 6, 8, 5, 11, 9};
  vector result = {3, 1, 2, 1, 1, 0};
  EXPECT_EQ(solution.canSeePersonsCount(heights), result);

  // 示例 2：
  // 输入：heights = [5,1,2,3,10]
  // 输出：[4,1,1,1,0]
  vector heights2 = {5, 1, 2, 3, 10};
  vector result2 = {4, 1, 1, 1, 0};
  EXPECT_EQ(solution.canSeePersonsCount(heights2), result2);
}
