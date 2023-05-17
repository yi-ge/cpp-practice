#include <array/determine_if_two_events_have_conflict.cpp>

TEST(判断两个事件是否存在冲突, haveConflict) {
  // 示例 1：
  // 输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
  // 输出：true
  // 解释：两个事件在 2:00 出现交集。
  Solution solution;
  vector<string> event1 = {"01:15", "02:00"};
  vector<string> event2 = {"02:00", "03:00"};
  EXPECT_TRUE(solution.haveConflict(event1, event2));

  // 示例 2：
  // 输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
  // 输出：true
  // 解释：两个事件的交集从 01:20 开始，到 02:00 结束。
  event1 = {"01:00", "02:00"};
  event2 = {"01:20", "03:00"};
  EXPECT_TRUE(solution.haveConflict(event1, event2));

  // 示例 3：
  // 输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
  // 输出：false
  // 解释：两个事件不存在交集。
  event1 = {"10:00", "11:00"};
  event2 = {"14:00", "15:00"};
  EXPECT_FALSE(solution.haveConflict(event1, event2));
}
