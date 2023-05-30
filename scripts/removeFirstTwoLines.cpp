// clang++ -std=c++17 -o .\removeFirstTwoLines.exe .\removeFirstTwoLines.cpp
#include <iostream>
#include <regex>
#include <string>

// 只删除字符串s的前两行 CRLF和LF
void removeFirstTwoLines(std::string &s) {
  std::smatch results;
  std::regex crlf_re("\r\n|\n");

  // 找到第一个换行
  std::regex_search(s, results, crlf_re);
  // 删除第一个换行之前的所有字符
  s.erase(0, results.position() + results.length());

  // 找到第二个换行
  std::regex_search(s, results, crlf_re);
  // 删除第二个换行之前的所有字符
  s.erase(0, results.position() + results.length());
}

int main() {
  std::string s1 = "line测试1 \r\n测试\r\nline3\r\nline4";
  removeFirstTwoLines(s1);

  std::string s2 = "line1 \nline2\nline3\nline4";
  removeFirstTwoLines(s2);

  std::string s3 = "line测试1 \nl测试ne2\r\nline3\r\nline4";
  removeFirstTwoLines(s3);
  std::cout << "Output s1: " << s1 << std::endl;
  std::cout << "Output s2: " << s2 << std::endl;
  std::cout << "Output s3: " << s3 << std::endl;
  return 0;
}