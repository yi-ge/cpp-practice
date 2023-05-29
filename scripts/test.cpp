#include <iostream>
#include <string>

bool isChineseCharacter(char16_t character) {
  return (character >= 0x4E00 && character <= 0x9FFF);
}

std::u16string insertEmptyByte(const std::u16string &str) {
  std::u16string result;
  for (size_t i = 0; i < str.size(); ++i) {
    result += str[i];
    if (isChineseCharacter(str[i])) {
      result += u'\x00';
    }
  }
  return result;
}

int main() {
  std::string input = "-gtest_color=yes "
                      "--gtest_filter=子串能表示从1到N数字的二进制串."
                      "queryString:检查二进制字符串字段.checkOnesSegment:"
                      "按字典序排在最后的子串.lastSubstring:段式回文";
  std::u16string input_utf16(input.begin(), input.end());
  std::u16string output_utf16 = insertEmptyByte(input_utf16);
  std::string output(output_utf16.begin(), output_utf16.end());
  std::cout << output << std::endl;
  return 0;
}
