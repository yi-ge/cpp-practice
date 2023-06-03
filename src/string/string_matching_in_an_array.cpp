// 数组中的字符串匹配
// https://leetcode.cn/problems/string-matching-in-an-array
// INLINE  ../../images/string/string_matching_in_an_array.jpeg
// 思路：字符串出现次数>1就说明有其他包含该字符串的字符串

#include <headers.hpp>
#include <utils.hpp>

class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    string out = Utils::join(words, '|'); // 将字符串数组用 '|' 连接成一个字符串
    vector<string> res;                   // 存储结果的字符串数组
    for (int i = 0; i < words.size(); ++i) {
      size_t first = out.find(
          words[i]); // 在连接后的字符串中查找当前字符串第一次出现的位置
      size_t last = out.rfind(
          words[i]); // 在连接后的字符串中查找当前字符串最后一次出现的位置
      // if (first != string::npos && last != string::npos && first != last)
      if (first !=
          last) // 如果当前字符串出现次数>1，说明有其他包含该字符串的字符串
      {
        res.push_back(words[i]); // 将当前字符串加入结果数组中
      }
    }
    return res; // 返回结果数组
  }
};