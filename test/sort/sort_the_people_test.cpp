#include <sort/sort_the_people.cpp>

TEST(按身高排序, sortPeople) {
  // 示例 1：
  // 输入：names = ["Mary","John","Emma"], heights = [180,165,170]
  // 输出：["Mary","Emma","John"]
  // 解释：Mary 最高，接着是 Emma 和 John 。
  Solution solution;
  vector<string> names = {"Mary", "John", "Emma"};
  vector<int> heights = {180, 165, 170};
  vector<string> result = solution.sortPeople(names, heights);
  vector<string> expected = {"Mary", "Emma", "John"};
  EXPECT_EQ(result, expected);

  // 示例 2：
  // 输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
  // 输出：["Bob","Alice","Bob"]
  // 解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
  names = {"Alice", "Bob", "Bob"};
  heights = {155, 185, 150};
  result = solution.sortPeople(names, heights);
  expected = {"Bob", "Alice", "Bob"};
  EXPECT_EQ(result, expected);
}
