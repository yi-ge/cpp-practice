#include <array/minimum_difficulty_of_a_job_schedule.cpp>
TEST(工作计划的最低难度, minDifficulty) {
  // 示例 1：
  // 输入：jobDifficulty = [6,5,4,3,2,1], d = 2
  // 输出：7
  // 解释：第一天，您可以完成前 5 项工作，总难度 = 6.
  // 第二天，您可以完成最后一项工作，总难度 = 1.
  // 计划表的难度 = 6 + 1 = 7
  Solution solution;
  vector<int> jobDifficulty{6, 5, 4, 3, 2, 1};
  int d = 2;
  EXPECT_EQ(solution.minDifficulty(jobDifficulty, d), 7);

  // 示例 2：
  // 输入：jobDifficulty = [9,9,9], d = 4
  // 输出：-1
  // 解释：就算你每天完成一项工作，仍然有一天是空闲的，你无法制定一份能够满足既定工作时间的计划表。
  jobDifficulty = {9, 9, 9};
  d = 4;
  EXPECT_EQ(solution.minDifficulty(jobDifficulty, d), -1);

  // 示例 3：
  // 输入：jobDifficulty = [1,1,1], d = 3
  // 输出：3
  // 解释：工作计划为每天一项工作，总难度为 3 。
  jobDifficulty = {1, 1, 1};
  d = 3;
  EXPECT_EQ(solution.minDifficulty(jobDifficulty, d), 3);

  // 示例 4：
  // 输入：jobDifficulty = [7,1,7,1,7,1], d = 3
  // 输出：15
  jobDifficulty = {7, 1, 7, 1, 7, 1};
  d = 3;
  EXPECT_EQ(solution.minDifficulty(jobDifficulty, d), 15);

  // 示例 5：
  // 输入：jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
  // 输出：843
  jobDifficulty = {11, 111, 22, 222, 33, 333, 44, 444};
  d = 6;
  EXPECT_EQ(solution.minDifficulty(jobDifficulty, d), 843);
}
