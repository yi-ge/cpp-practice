// 重新排列单词间的空格
// https://leetcode.cn/problems/rearrange-spaces-between-words
// INLINE  ../../images/string/rearrange_spaces_between_words.jpeg
// 解题思路：对单词和空格计数，然后单词数/空格数向下取整并补齐。

#include <headers.hpp>

class Solution {
public:
  string reorderSpaces(string text) {
    vector<string> vec; // 用于存放分割后的单词
    stringstream in_text(text); // 输入流，用于分割单词
    string word, ans;
    int count = 0; // 统计单词总长度
    while (in_text >> word) {
      vec.push_back(word);
      count += word.size();
    }
    if (vec.size() == 1) // 只有一个单词时，直接返回该单词
      ans = vec[0];
    else {
      string space((text.size() - count) / (vec.size() - 1), ' '); // 计算每个单词之间的空格数
      for (int i = 0; i < vec.size() - 1; ++i)
        ans += vec[i] + space; // 拼接单词和空格
      ans += vec.back(); // 拼接最后一个单词
    }
    return ans + string(text.size() - ans.size(), ' '); // 在最后补齐剩余的空格
  }
};