// 重新排列单词间的空格
// https://leetcode.cn/problems/rearrange-spaces-between-words
// INLINE  ../../images/string/rearrange_spaces_between_words.jpeg
// 解题思路：对单词和空格计数，然后单词数/空格数向下取整并补齐。
#include <headers.hpp>

class Solution {
public:
  string reorderSpaces(string text) {
    vector<string> vec;
    stringstream in_text(text);
    string word, ans;
    int count = 0;
    while (in_text >> word) {
      vec.push_back(word);
      count += word.size();
    }
    if (vec.size() == 1)
      ans = vec[0];
    else {
      string space((text.size() - count) / (vec.size() - 1), ' ');
      for (int i = 0; i < vec.size() - 1; ++i)
        ans += vec[i] + space;
      ans += vec.back();
    }
    return ans + string(text.size() - ans.size(), ' ');
  }
};