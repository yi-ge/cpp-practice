#include <math/day_of_the_week.cpp>

TEST(一周中的第几天, dayOfTheWeek) {
  Solution solution;
  // 示例 1：
  // 输入：day = 31, month = 8, year = 2019
  // 输出："Saturday"
  int day = 31, month = 8, year = 2019;
  EXPECT_EQ(solution.dayOfTheWeek(day, month, year), "Saturday");

  // 示例 2：
  // 输入：day = 18, month = 7, year = 1999
  // 输出："Sunday"
  day = 18, month = 7, year = 1999;
  EXPECT_EQ(solution.dayOfTheWeek(day, month, year), "Sunday");

  // 示例 3：
  // 输入：day = 15, month = 8, year = 1993
  // 输出："Sunday"
  day = 15, month = 8, year = 1993;
  EXPECT_EQ(solution.dayOfTheWeek(day, month, year), "Sunday");
}
