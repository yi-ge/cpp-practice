#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Utils
{
public:
  static vector<string> split(const string &s, char ch)
  {
    int pos = 0;
    int start = 0;
    vector<string> ret;
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

  static string join(vector<string> &words, char ch)
  {
    string chStr;
    chStr = ch;
    string ans;
    for (long int i = 0; i + 1 < words.size(); i++)
    {
      ans.append(words[i]);
      ans.append(chStr);
    }
    ans.append(words.back());
    return ans;
  }
};
