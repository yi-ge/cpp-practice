// 在每个中文段之间的非中文字符之前替换一个中文字符为 *
// clang++ -std=c++17 -o .\replace_last_chinese_character.exe
// .\replace_last_chinese_character.cpp
#include <iostream>
#include <string>
#include <vector>

// 计算UTF-8字符的字节数
int countUtf8CharBytes(unsigned char ch) {
  if (ch < 0x80) {
    return 1;
  } else if ((ch & 0xE0) == 0xC0) {
    return 2;
  } else if ((ch & 0xF0) == 0xE0) {
    return 3;
  } else if ((ch & 0xF8) == 0xF0) {
    return 4;
  }
  // invalid UTF-8 character
  return 0;
}

std::string replaceLastChineseCharBeforeDot(const std::string &s) {
  std::string result = s;
  std::vector<int> positionsToReplace;

  // Find all '.' positions and check if the previous character is a Chinese
  // character
  for (int i = 0; i < s.size();) {
    int charBytes = countUtf8CharBytes((unsigned char)s[i]);
    if (charBytes == 0) {
      // Invalid UTF-8 character, skip it
      ++i;
      continue;
    }
    if (i + charBytes < s.size() && s[i + charBytes] == '.') {
      if (charBytes == 3) { // Check if it is a 3-byte UTF-8 character, which
                            // are Chinese characters in UTF-8
        positionsToReplace.push_back(i);
      }
    }
    i += charBytes;
  }

  // Replace the Chinese characters
  for (const auto &pos : positionsToReplace) {
    result.replace(pos, 3, "***");
  }

  // Replace "***" with "*"
  size_t pos = result.find("***");
  while (pos != std::string::npos) {
    result.replace(pos, 3, "*");
    pos = result.find("***", pos + 1);
  }

  return result;
}

int main() {
  std::string test_string = "按列翻转得到最大值等行数.maxEqualRowsAfterFlips";
  std::string result = replaceLastChineseCharBeforeDot(test_string);
  std::cout << "Original string: " << test_string << std::endl;
  std::cout << "Modified string: " << result << std::endl;

  return 0;
}

// #include <iostream>
// #include <string>

// std::string replaceLastChineseChar(std::string s) {
//   size_t pos = 0;

//   while ((pos = s.find('.', pos)) != std::string::npos) {
//     // 如果前面有足够的字符（3个字节代表一个中文字符）
//     if (pos >= 3) {
//       s[pos - 3] = '*';
//       // 将剩余的2个字节设为控制字符，这样在UTF-8中不会显示为乱码
//       s[pos - 2] = s[pos - 1] = '*';
//     }
//     pos++;
//   }

//   return s;
// }

// int main() {
//   std::string test_string =
//       "子串能表示从1到N数字的二进制串.queryString:检查二进制字符串字段."
//       "checkOnesSegment:按字典序排在最后的子串.lastSubstring:段式";
//   std::string result = replaceLastChineseChar(test_string);
//   std::cout << "Original string: " << test_string << std::endl;
//   std::cout << "Modified string: " << result << std::endl;

//   return 0;
// }
