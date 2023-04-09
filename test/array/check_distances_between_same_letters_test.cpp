#include <array/check_distances_between_same_letters.cpp>

TEST(检查相同字母间的距离, checkDistances) {
  // 示例 1：
  // 输入：s = "abaccb", distance =
  // [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0] 输出：true 解释：
  // - 'a' 在下标 0 和下标 2 处出现，所以满足 distance[0] = 1 。
  // - 'b' 在下标 1 和下标 5 处出现，所以满足 distance[1] = 3 。
  // - 'c' 在下标 3 和下标 4 处出现，所以满足 distance[2] = 0 。
  // 注意 distance[3] = 5 ，但是由于 'd' 没有在 s 中出现，可以忽略。
  // 因为 s 是一个匀整字符串，返回 true 。
  Solution solution;
  std::string s1 = "abaccb";
  std::vector<int> distance1 = {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(solution.checkDistances(s1, distance1), true);

  // 示例 2：
  // 输入：s = "aa", distance =
  // [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0] 输出：false 解释：
  // - 'a' 在下标 0 和 1 处出现，所以两次出现之间的字母数量为 0 。
  // 但是 distance[0] = 1 ，s 不是一个匀整字符串。
  std::string s2 = "aa";
  std::vector<int> distance2 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(solution.checkDistances(s2, distance2), false);
}
