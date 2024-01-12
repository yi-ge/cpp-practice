#include <array/count_common_words_with_one_occurrence.cpp>

TEST(统计出现过一次的公共字符串, countWords) {
  Solution solution;
  // 示例 1：
  // 输入：words1 = ["leetcode","is","amazing","as","is"], words2 =
  // ["amazing","leetcode","is"] 输出：2 解释：
  // - "leetcode" 在两个数组中都恰好出现一次，计入答案。
  // - "amazing" 在两个数组中都恰好出现一次，计入答案。
  // - "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
  // - "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
  // 所以，有 2 个字符串在两个数组中都恰好出现了一次。
  vector<string> words1 = {"leetcode", "is", "amazing", "as", "is"};
  vector<string> words2 = {"amazing", "leetcode", "is"};
  EXPECT_EQ(solution.countWords(words1, words2), 2);

  // 示例 2：
  // 输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
  // 输出：0
  // 解释：没有字符串在两个数组中都恰好出现一次。
  words1 = {"b", "bb", "bbb"};
  words2 = {"a", "aa", "aaa"};
  EXPECT_EQ(solution.countWords(words1, words2), 0);

  // 示例 3：
  // 输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
  // 输出：1
  // 解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
  words1 = {"a", "ab"};
  words2 = {"a", "a", "a", "ab"};
  EXPECT_EQ(solution.countWords(words1, words2), 1);
}
