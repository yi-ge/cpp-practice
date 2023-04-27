#include <array/longest_string_chain.cpp>

TEST(最长字符串链, longestStrChain) {
  // 示例 1：
  // 输入：words = ["a","b","ba","bca","bda","bdca"]
  // 输出：4
  // 解释：最长单词链之一为 ["a","ba","bda","bdca"]
  Solution solution;
  vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
  EXPECT_EQ(solution.longestStrChain(words), 4);

  // 示例 2:
  // 输入：words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
  // 输出：5
  // 解释：所有的单词都可以放入单词链 ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
  words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
  EXPECT_EQ(solution.longestStrChain(words), 5);

  // 示例 3:
  // 输入：words = ["abcd","dbqca"]
  // 输出：1
  // 解释：字链["abcd"]是最长的字链之一。
  // ["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
}
