#include <sort/compare_strings_by_frequency_of_the_smallest_character.cpp>

TEST(比较字符串最小字母出现频次, numSmallerByFrequency) {
  Solution solution;
  // 示例 1：
  // 输入：queries = ["cbd"], words = ["zaaaz"]
  // 输出：[1]
  // 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
  vector<string> queries = {"cbd"};
  vector<string> words = {"zaaaz"};
  vector<int> result = {1};
  EXPECT_EQ(solution.numSmallerByFrequency(queries, words), result);

  // 示例 2：
  // 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
  // 输出：[1,2]
  // 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都
  // > f("cc")。
  queries = {"bbb", "cc"};
  words = {"a", "aa", "aaa", "aaaa"};
  result = {1, 2};
  EXPECT_EQ(solution.numSmallerByFrequency(queries, words), result);
}
