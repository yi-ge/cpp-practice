#include <string/number_of_valid_clock_times.cpp>
TEST(有效时间的数目, countTime) {
  // 示例 1：
  // 输入：time = "?5:00"
  // 输出：2
  // 解释：我们可以将 ? 替换成 0 或 1 ，得到 "05:00" 或者 "15:00"
  // 。注意我们不能替换成 2 ，因为时间 "25:00" 是无效时间。所以我们有两个选择。
  Solution solution;
  string time = "?5:00";
  EXPECT_EQ(solution.countTime(time), 2);

  // 示例 2：
  // 输入：time = "0?:0?"
  // 输出：100
  // 解释：两个 ? 都可以被 0 到 9 之间的任意数字替换，所以我们总共有 100
  // 种选择。
  time = "0?:0?";
  EXPECT_EQ(solution.countTime(time), 100);

  // 示例 3：
  // 输入：time = "??:??"
  // 输出：1440
  // 解释：小时总共有 24 种选择，分钟总共有 60 种选择。所以总共有 24 * 60 = 1440
  // 种选择。
  time = "??:??";
  EXPECT_EQ(solution.countTime(time), 1440);
}
