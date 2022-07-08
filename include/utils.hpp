#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Utils
{
public:
  static vector<string_view> split(const string &str, char ch)
  {
    int pos = 0;
    int start = 0;
    string_view s(str);
    vector<string_view> ret;
    while (pos < s.size())
    {
      while (pos < s.size() && s[pos] == ch)
      {
        pos++;
      }
      start = pos;
      while (pos < s.size() && s[pos] != ch)
      {
        pos++;
      }
      if (start < s.size())
      {
        ret.emplace_back(s.substr(start, pos - start));
      }
    }
    return ret;
  }
  static string join(vector<string_view> words, char ch)
  {
    string chStr;
    chStr = ch;
    string ans;
    for (int i = 0; i < words.size() - 1; i++)
    {
      ans.append(words[i]);
      ans.append(chStr);
    }
    ans.append(words.back());
    return ans;
  }
};
