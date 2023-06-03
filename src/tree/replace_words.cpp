// 单词替换
// https://leetcode.cn/problems/replace-words
// INLINE  ../../images/tree/replace_words.jpeg
#include <headers.hpp> 
#include <utils.hpp> 

class Solution 
{
public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    unordered_set<string> dictionarySet;
    for (auto &word : dictionary)
    {
      // 将单词插入字典集合
      dictionarySet.emplace(word);
    }

    vector<string> words = Utils::split(sentence, ' ');
    for (auto &word : words)
    {
      for (int i = 0; i < word.size(); ++i)
      {
        // 如果单词的前缀已经在字典集合中，就将这个单词用前缀代替
        if (dictionarySet.find(word.substr(0, i + 1)) != dictionarySet.end())
        {
          word = word.substr(0, i + 1);
          break;
        }
      }
    }

    // 将处理后的单词拼接起来，返回结果
    return Utils::join(words, ' ');
  }
};