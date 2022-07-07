// #include "replace_words.hpp"
#include <replace_words.cpp>

TEST(单词替换, replaceWords)
{
  // 示例 1：
  // 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
  // 输出："the cat was rat by the bat"
  vector<string> dictionary;
  dictionary.push_back("cat");
  dictionary.push_back("bat");
  dictionary.push_back("rat");
  string sentence = "the cattle was rattled by the battery";
  Solution solution;
  string outStr = solution.replaceWords(dictionary, sentence);
  EXPECT_STREQ(outStr.c_str(), "the cat was rat by the bat");

  // 示例 2：
  // 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
  // 输出："a a b c"
  string str[] = {"a", "b", "c"};
  vector<string> dictionary2(str, str + 3);
  string sentence2 = "aadsfasf absbs bbab cadsfafs";
  string outStr2 = solution.replaceWords(dictionary2, sentence2);
  EXPECT_STREQ(outStr2.c_str(), "a a b c");
}
