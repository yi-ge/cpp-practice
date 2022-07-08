// 单词替换
// https://leetcode.cn/problems/replace-words
// INLINE  ../images/tree/replace_words.jpeg
#include <headers.hpp>
#include <utils.hpp>

class Solution
{
public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    unordered_set<string_view> dictionarySet;
    for (auto &word : dictionary)
    {
      // dictionarySet.insert(word);
      dictionarySet.emplace(word);
    }

    vector<string_view> words = Utils::split(sentence, ' ');
    for (auto &word : words)
    {
      for (int i = 0; i < word.size(); ++i)
      {
        // if (dictionarySet.count(word.substr(0, i + 1)))
        if (dictionarySet.find(word.substr(0, i + 1)) != dictionarySet.end())
        {
          word = word.substr(0, i + 1);
          break;
        }
      }
    }

    return Utils::join(words, ' ');
  }
};