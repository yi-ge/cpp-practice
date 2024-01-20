#include <array/split_strings_by_separator.cpp>

TEST(按分隔符拆分字符串, splitWordsBySeparator) {
  Solution solution;
  // 示例 1：
  // 输入：words = ["one.two.three","four.five","six"], separator = "."
  // 输出：["one","two","three","four","five","six"]
  // 解释：在本示例中，我们进行下述拆分：

  // "one.two.three" 拆分为 "one", "two", "three"
  // "four.five" 拆分为 "four", "five"
  // "six" 拆分为 "six"

  // 因此，结果数组为 ["one","two","three","four","five","six"] 。
  vector<string> words = {"one.two.three", "four.five", "six"};
  char separator = '.';
  vector<string> result = {"one", "two", "three", "four", "five", "six"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, separator), result);

  // 示例 2：
  // 输入：words = ["$easy$","$problem$"], separator = "$"
  // 输出：["easy","problem"]
  // 解释：在本示例中，我们进行下述拆分：

  // "$easy$" 拆分为 "easy"（不包括空字符串）
  // "$problem$" 拆分为 "problem"（不包括空字符串）

  // 因此，结果数组为 ["easy","problem"] 。
  words = {"$easy$", "$problem$"};
  separator = '$';
  result = {"easy", "problem"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, separator), result);

  // 示例 3：
  // 输入：words = ["|||"], separator = "|"
  // 输出：[]
  // 解释：在本示例中，"|||"
  // 的拆分结果将只包含一些空字符串，所以我们返回一个空数组 [] 。
  words = {"|||"};
  separator = '|';
  result = {};
  EXPECT_EQ(solution.splitWordsBySeparator(words, separator), result);
}
