// 数组中的字符串匹配
// https://leetcode.cn/problems/string-matching-in-an-array
// INLINE  ../images/string/string_matching_in_an_array.jpeg
#include <headers.hpp>
#include <utils.hpp>

class Solution
{
public:
  vector<string> stringMatching(vector<string> &words)
  {
    string out = Utils::join(words, '|');
    vector<string> res;
    for (int i = 0; i < words.size(); ++i)
    {
      size_t first = out.find(words[i]);
      size_t last = out.rfind(words[i]);
      // if (first != string::npos && last != string::npos && first != last)
      if (first != last)
      {
        res.push_back(words[i]);
      }
    }
    return res;
  }
};