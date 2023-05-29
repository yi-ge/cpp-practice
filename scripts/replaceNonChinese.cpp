// C++
// 实现替换中文中的非中文。有一段字符串是这样的：“子串能表示从1到N数字的二进制串.queryString:检查二进制字符串字段.checkOnesSegment:按字典序排在最后的子串.lastSubstring:总持续时间可被60整除的歌曲,
// numPairsDivisibleBy60”，请检查每一个句号（"."）之前的内容是否是中文，如果是中文，则检查这一句话是否包含非中文，如果包含非中文，则将非中文部分替换为“*”。例如上面的示例，需要修改为“子串能表示从*到*数字的二进制串.queryString:检查二进制字符串字段.checkOnesSegment:按字典序排在最后的子串.lastSubstring:总持续时间可被*整除的歌曲,
// numPairsDivisibleBy60”。 为了实现这个功能，我们可以使用以下步骤：

// 1. 将输入字符串按照句号（"."）进行分割，得到一个包含各个子串的数组。
// 2. 遍历这个数组，对每个子串进行处理：
//    a. 检查子串的第一个字符是否是中文字符。
//    b. 如果是中文字符，遍历子串中的每个字符，将非中文字符替换为“*”。
//    c. 将处理后的子串添加到新的字符串中，用句号（"."）进行连接。
// 3. 返回处理后的字符串。

// 注意：这个实现仅支持处理基本的
// BMP（基本多文种平面）中的中文字符。对于更高级的 Unicode
// 字符（如扩展汉字），可能需要使用更复杂的方法来检测和处理。

// clang++ -std=c++17 -lAdvapi32 -o .\replaceNonChinese.exe
// .\replaceNonChinese.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isChinese(const std::string &str, size_t i) {
  if (str[i] & 0x80) {
    unsigned char c1 = static_cast<unsigned char>(str[i]);
    unsigned char c2 = static_cast<unsigned char>(str[i + 1]);
    unsigned char c3 = static_cast<unsigned char>(str[i + 2]);
    return (c1 >= 0xE4 && c1 <= 0xE9) && (c2 >= 0x80 && c2 <= 0xBF) &&
           (c3 >= 0x80 && c3 <= 0xBF);
  }
  return false;
}

std::string replaceNonChinese(const std::string &str, bool replace) {
  std::string result;

  for (size_t i = 0; i < str.size(); ++i) {
    if (i + 2 < str.size() && isChinese(str, i)) {
      result.push_back(str[i]);
      result.push_back(str[i + 1]);
      result.push_back(str[i + 2]);
      i += 2;
    } else {
      if (replace) {
        result.push_back('*');
      } else {
        result.push_back(str[i]);
      }
    }
  }

  return result;
}

std::vector<std::string> split(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

std::string processString(const std::string &input) {
  std::vector<std::string> sentences = split(input, '.');
  std::string result;
  for (const std::string &sentence : sentences) {
    if (!sentence.empty()) {
      if (isChinese(sentence, 0)) {
        result += replaceNonChinese(sentence, true);
      } else {
        result += replaceNonChinese(sentence, false);
      }
    }
    result += '.';
  }
  return result;
}

int main() {
  std::string input =
      "子串能表示从1到N数字的二进制串.queryString:检查二进制字符串字段."
      "checkOnesSegment:按字典序排在最后的子串.lastSubstring:"
      "总持续时间可被60整除的歌曲.numPairsDivisibleBy60";
  std::string output = processString(input);
  std::cout << "Output: " << output << std::endl;
  return 0;
}