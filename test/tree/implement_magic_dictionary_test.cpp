#include <tree/implement_magic_dictionary.cpp>

TEST(实现一个魔法字典, MagicDictionary)
{
  // 示例：
  // 输入
  // ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
  // [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
  // 输出
  // [null, null, false, true, false, false]

  MagicDictionary magicDictionary;
  string dic[] = {"hello", "leetcode"};
  vector<string> dictionary(dic, dic + 2);
  magicDictionary.buildDict(dictionary);
  EXPECT_FALSE(magicDictionary.search("hello"));     // 返回 False
  EXPECT_TRUE(magicDictionary.search("hhllo"));      // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
  EXPECT_FALSE(magicDictionary.search("hell"));      // 返回 False
  EXPECT_FALSE(magicDictionary.search("leetcoded")); // 返回 False

  MagicDictionary magicDictionary2;
  string dic2[] = {"hello", "hallo", "leetcode"};
  vector<string> dictionary2(dic2, dic2 + 3);
  magicDictionary2.buildDict(dictionary2);
  EXPECT_TRUE(magicDictionary2.search("hello"));      // 返回 False
  EXPECT_TRUE(magicDictionary2.search("hhllo"));      // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
  EXPECT_FALSE(magicDictionary2.search("hell"));      // 返回 False
  EXPECT_FALSE(magicDictionary2.search("leetcoded")); // 返回 False
}
