// 仅适用于Windows的脚本，用于执行命令并捕获输出(输出到日志时保留ANSI转义序列[颜色信息]，输出到终端移除颜色)。
// clang++ -std=c++17 -lAdvapi32 -o .\executionWrapper.exe
// .\executionWrapper.cpp
#include <algorithm>
#include <array>
#include <chrono>
#include <codecvt>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <locale>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
// #include <iconv.h>

// 检查Windows系统是否开启了“使用 Unicode UTF-8 提供全球语言支持”
bool check_utf8_support() {
  HKEY hKey;
  constexpr auto registry_key =
      TEXT("SYSTEM\\CurrentControlSet\\Control\\Nls\\CodePage");
  constexpr auto value_name = TEXT("ACP");

  if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, registry_key, 0, KEY_QUERY_VALUE,
                   &hKey) == ERROR_SUCCESS) {
    TCHAR acp_value[256];
    DWORD buffer_size = sizeof(acp_value);
    DWORD data_type;

    if (RegQueryValueEx(hKey, value_name, nullptr, &data_type,
                        (LPBYTE)&acp_value, &buffer_size) == ERROR_SUCCESS &&
        data_type == REG_SZ) {
      RegCloseKey(hKey);

#ifdef UNICODE
      return std::wstring(acp_value) == L"65001";
#else
      return std::string(acp_value) == "65001";
#endif
    }
    RegCloseKey(hKey);
  }

  return false;
}

// Method to parse the command line arguments
void parse_arguments(int argc, char **argv, std::string &command,
                     std::string &logDir) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-c") && (i + 1 < argc)) {
      command = argv[++i];
    } else if ((arg == "-l") && (i + 1 < argc)) {
      logDir = argv[++i];
    } else {
      std::cerr << "Unknown option: " << arg << std::endl;
      exit(1);
    }
  }
}

std::string generate_unique_path() {
  auto now = std::chrono::system_clock::now();
  auto epoch_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                        now.time_since_epoch())
                        .count();
  std::ostringstream oss;
  oss << "temp_output_" << epoch_time << ".txt";
  return oss.str();
}

std::wstring Utf8ToUtf16(const std::string &utf8) {
  int requiredSize =
      MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
  std::wstring utf16(requiredSize, L'\0');
  MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &utf16[0], requiredSize);
  return utf16;
}

std::string generate_temp_filename() {
  // 获取系统临时文件夹的路径
  char temp_path[MAX_PATH];
  GetTempPath(MAX_PATH, temp_path);

  // 在临时文件夹中生成带时间戳的文件名
  std::time_t t = std::time(nullptr);
  char buffer[100];
  std::strftime(buffer, sizeof(buffer), "temp_%Y%m%d%H%M%S.txt",
                std::localtime(&t));

  // 返回完整的绝对路径
  return std::string(temp_path) + buffer;
}

// Function to execute a command and capture the output
std::string exec_powershell(const std::string &cmd) {
  std::string utf8_encoding = "$OutputEncoding = [Console]::OutputEncoding ="
                              "[System.Text.Encoding]::UTF8\n";
  std::string command = "powershell.exe -NoLogo -NonInteractive -Command \"" +
                        utf8_encoding + cmd + "\"";
  // std::string command =
  //     "powershell.exe -NoLogo -NonInteractive -Command \"chcp 65001 > NUL &&
  //     " + cmd + "\"";
  // std::string command = "powershell.exe -Command \"" + cmd + "\"";

  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  SECURITY_ATTRIBUTES sa;
  HANDLE g_hChildStd_OUT_Rd = NULL;
  HANDLE g_hChildStd_OUT_Wr = NULL;

  ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
  ZeroMemory(&si, sizeof(STARTUPINFO));
  si.cb = sizeof(STARTUPINFO);
  si.dwFlags |= STARTF_USESTDHANDLES;

  sa.nLength = sizeof(SECURITY_ATTRIBUTES);
  sa.bInheritHandle = TRUE;
  sa.lpSecurityDescriptor = NULL;

  if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &sa, 0)) {
    exit(EXIT_FAILURE);
  }

  si.hStdOutput = g_hChildStd_OUT_Wr;

  if (!CreateProcess(nullptr, const_cast<char *>(command.c_str()), nullptr,
                     nullptr, TRUE, CREATE_NO_WINDOW, nullptr, nullptr, &si,
                     &pi)) {
    exit(EXIT_FAILURE);
  }

  CloseHandle(g_hChildStd_OUT_Wr);

  DWORD dwRead;
  CHAR chBuf[4096];
  std::string result;
  bool success = false;
  do {
    success = ReadFile(g_hChildStd_OUT_Rd, chBuf, 4096, &dwRead, nullptr);
    if (success && dwRead > 0) {
      result.append(chBuf, dwRead);
    }
  } while (success && dwRead > 0);

  WaitForSingleObject(pi.hProcess, INFINITE);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  CloseHandle(g_hChildStd_OUT_Rd);

  return result;
}
// std::string exec_powershell(const std::string &cmd) {
//   std::wstring command =
//       L"powershell.exe -Command \"" + Utf8ToUtf16(cmd) + L"\"";

//   STARTUPINFOW si;
//   PROCESS_INFORMATION pi;
//   SECURITY_ATTRIBUTES sa;
//   HANDLE g_hChildStd_OUT_Rd = NULL;
//   HANDLE g_hChildStd_OUT_Wr = NULL;

//   ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
//   ZeroMemory(&si, sizeof(STARTUPINFOW));
//   si.cb = sizeof(STARTUPINFOW);
//   si.dwFlags |= STARTF_USESTDHANDLES;

//   sa.nLength = sizeof(SECURITY_ATTRIBUTES);
//   sa.bInheritHandle = TRUE;
//   sa.lpSecurityDescriptor = NULL;

//   if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &sa, 0)) {
//     exit(EXIT_FAILURE);
//   }

//   si.hStdOutput = g_hChildStd_OUT_Wr;

//   if (!CreateProcessW(nullptr, const_cast<wchar_t *>(command.c_str()),
//   nullptr,
//                       nullptr, TRUE, CREATE_NO_WINDOW, nullptr, nullptr, &si,
//                       &pi)) {
//     exit(EXIT_FAILURE);
//   }

//   CloseHandle(g_hChildStd_OUT_Wr);

//   DWORD dwRead;
//   CHAR chBuf[4096];
//   std::string result;
//   bool success = false;
//   do {
//     success = ReadFile(g_hChildStd_OUT_Rd, chBuf, 4096, &dwRead, nullptr);
//     if (success && dwRead > 0) {
//       result.append(chBuf, dwRead);
//     }
//   } while (success && dwRead > 0);

//   WaitForSingleObject(pi.hProcess, INFINITE);
//   CloseHandle(pi.hProcess);
//   CloseHandle(pi.hThread);
//   CloseHandle(g_hChildStd_OUT_Rd);

//   return result;
// }

// Function to execute a command and capture the output
std::string exec_and_capture(const char *cmd, const std::string &logDir) {
  std::array<char, 128> buffer;
  std::string result;

  // std::ofstream errorLogFile(logDir + "/command_sys_exec.log",
  //                            std::ios_base::app);
  // errorLogFile << "_popen之前:" << cmd << std::endl;
  // errorLogFile.close();

  FILE *pipe = _popen(cmd, "r");

  // std::ofstream errorLogFile2(logDir + "/command_sys_exec2.log",
  //                             std::ios_base::app);
  // errorLogFile2 << "_popen后" << std::endl;
  // errorLogFile2.close();

  if (!pipe) {
    // throw std::runtime_error("_popen() failed!");
    std::ofstream errorLogFile(logDir + "/command_sys_error.log",
                               std::ios_base::app);
    errorLogFile << "_popen() failed!" << std::endl;
    errorLogFile.close();
  }

  while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
    result += buffer.data();
  }

  int exitStatus = _pclose(pipe);

  // 将命令字符串和输出写入 command_output.log 文件
  // std::ofstream outputLogFile(logDir + "/command_output.log",
  //                             std::ios_base::app);
  // outputLogFile << "Command: " << cmd << std::endl;
  // outputLogFile << "Output: " << result << std::endl;
  // outputLogFile.close();

  // 如果命令执行不成功，将错误信息写入 command_error.log 文件
  if (exitStatus != 0) {
    std::ofstream errorLogFile(logDir + "/command_error.log",
                               std::ios_base::app);
    errorLogFile << "Command exited with non-zero status: " << exitStatus
                 << std::endl;
    errorLogFile.close();
  }

  return result;
}
// std::string exec_and_capture(const char *cmd, const std::string &logDir) {
//   constexpr size_t BUFFER_SIZE = 128;
//   std::array<char, BUFFER_SIZE> buffer{};
//   std::string result;

//   // 创建临时文件名以存储命令输出
//   std::string temp_file = generate_unique_path();

//   // 将命令的输出重定向到临时文件
//   std::string modified_cmd = std::string(cmd) + " >" + temp_file + " 2>&1";

//   // 使用 std::system 执行命令
//   int exitStatus = std::system(modified_cmd.c_str());

//   // 读取临时文件的内容
//   std::ifstream inputFile(temp_file);
//   while (inputFile.getline(buffer.data(), BUFFER_SIZE)) {
//     result += buffer.data();
//     result += '\n';
//   }
//   inputFile.close();

//   // 删除临时文件
//   std::filesystem::remove(temp_file);

//   // 如果命令执行不成功，将错误信息写入 command_error.log 文件
//   if (exitStatus != 0) {
//     std::ofstream errorLogFile(logDir + "/command_error.log",
//                                std::ios_base::app);
//     errorLogFile << "Command exited with non-zero status: " << exitStatus
//                  << std::endl;
//     errorLogFile.close();
//   }

//   return result;
// }

// Limit the lines of a file
void limit_file_lines(const std::string &filePath, int maxLines) {
  std::ifstream file(filePath);
  std::deque<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
    while (lines.size() > maxLines) {
      lines.pop_front();
    }
  }
  file.close();

  std::ofstream fileOut(filePath);
  for (const auto &line : lines) {
    fileOut << line << std::endl;
  }
  fileOut.close();
}

// 将utf8字符串转换为gbk字符串
std::string utf8_to_gbk(const std::string &utf8_str) {
  int wide_len =
      MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, nullptr, 0);
  std::wstring wide_str(wide_len, 0);
  MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, &wide_str[0], wide_len);

  int gbk_len = WideCharToMultiByte(CP_ACP, 0, wide_str.c_str(), -1, nullptr, 0,
                                    nullptr, nullptr);
  std::string gbk_str(gbk_len, 0);
  WideCharToMultiByte(CP_ACP, 0, wide_str.c_str(), -1, &gbk_str[0], gbk_len,
                      nullptr, nullptr);

  return gbk_str;
}

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

  // // Replace "***" with "*"
  // size_t pos = result.find("***");
  // while (pos != std::string::npos) {
  //   result.replace(pos, 3, "*");
  //   pos = result.find("***", pos + 1);
  // }

  return result;
}

bool isChinese(const std::string &str, size_t i) {
  // Check for GBK encoding
  if (str[i] & 0x80) {
    unsigned char c1 = str[i];
    unsigned char c2 = str[i + 1];
    unsigned char c3 = str[i + 2];
    if ((c1 >= 0xE4 && c1 <= 0xE9) && (c2 >= 0x80 && c2 <= 0xBF) &&
        (c3 >= 0x80 && c3 <= 0xBF)) {
      return true;
    }
  }
  // Check for UTF-8 encoding
  if ((str[i] & 0xE0) == 0xC0 && (str[i + 1] & 0xC0) == 0x80 &&
      (str[i + 2] & 0xC0) == 0x80) {
    return true;
  }
  return false;
}

std::string replaceNonChinese(const std::string &str) {
  std::string result;
  bool inChinese = false;

  for (size_t i = 0; i < str.size(); ++i) {
    if (i + 2 < str.size() && isChinese(str, i)) {
      // 检测中文字符
      inChinese = true;
      result.push_back(str[i]);
      result.push_back(str[i + 1]);
      result.push_back(str[i + 2]);
      i += 2;
    } else if (isdigit(str[i])) {
      // 检测阿拉伯数字
      result.push_back('*');
    } else {
      // 其他字符
      if (!inChinese) {
        result.push_back(str[i]);
      } else {
        while (i < str.size() && !isChinese(str, i)) {
          result.push_back('*');
          result.push_back('*');
          i++;
        }
        inChinese = false;
        i--;
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
  std::vector<std::string> sentences = split(input, ':');
  std::string result;
  for (size_t i = 0; i < sentences.size(); ++i) {
    std::vector<std::string> parts = split(sentences[i], '.');
    for (size_t j = 0; j < parts.size(); ++j) {
      if (!parts[j].empty()) {
        if (j < parts.size() - 1 && isChinese(parts[j], 0)) {
          result += replaceNonChinese(parts[j]);
        } else {
          result += parts[j];
        }
      }
      if (j < parts.size() - 1) {
        result += '.'; // 内部拼接用.
      }
    }
    if (i < sentences.size() - 1) {
      result += ':'; // 句子之间拼接用:
    }
  }
  return result;
}

std::string exec_powershell_with_file(const std::string &cmd) {
  // 提取 --gtest_filter 参数的内容
  std::size_t filter_start = cmd.find("--gtest_filter=");
  if (filter_start == std::string::npos) {
    return ""; // 若找不到 --gtest_filter 参数，返回空字符串
  }
  filter_start += 15; // 跳过 --gtest_filter= 部分
  std::size_t filter_end = cmd.find(" ", filter_start);
  std::string filter_content =
      cmd.substr(filter_start, filter_end - filter_start);

  // 替换中文中的非中文字符
  filter_content = processString(filter_content);

  // “.”前的最后一个中文字符替换为*
  filter_content = replaceLastChineseCharBeforeDot(filter_content);

  // 将参数内容写入临时文件
  std::string temp_filename = generate_temp_filename();
  std::ofstream temp_file(temp_filename);
  temp_file << filter_content;
  temp_file.close();

  // 构造新命令，从文件中读取参数内容
  std::string new_cmd =
      cmd.substr(0, filter_start) + "$(Get-Content " + temp_filename + ") ";
  if (filter_end != std::string::npos) {
    new_cmd += cmd.substr(filter_end);
  }

  // std::ofstream errorLogFile(
  //     "D:\\Project\\cpp-practice\\build\\command_sys_exec.log",
  //     std::ios_base::app);
  // errorLogFile << "命令:" << new_cmd << std::endl;
  // errorLogFile.close();

  // 调用 exec_powershell 函数执行新命令
  std::string result = exec_powershell(new_cmd);

  // 删除临时文件
  std::remove(temp_filename.c_str());

  return result;
}

// 将gbk字符串转换为utf8字符串
std::string gbk_to_utf8(const std::string &gbk_str) {
  if (gbk_str.empty()) {
    return std::string();
  }

  int wide_len =
      MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, gbk_str.c_str(),
                          static_cast<int>(gbk_str.size()), nullptr, 0);

  if (wide_len == 0 && GetLastError() != ERROR_NO_UNICODE_TRANSLATION) {
    // Error handling
    return std::string();
  } else if (wide_len == 0) {
    wide_len =
        MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(),
                            static_cast<int>(gbk_str.size()), nullptr, 0);
  }

  std::vector<wchar_t> wide_str(wide_len);
  MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(),
                      static_cast<int>(gbk_str.size()), &wide_str[0], wide_len);

  int utf8_len = WideCharToMultiByte(CP_UTF8, 0, wide_str.data(), wide_len,
                                     nullptr, 0, nullptr, nullptr);

  if (utf8_len == 0) {
    // Error handling
    return std::string();
  }

  std::vector<char> utf8_str(utf8_len);
  WideCharToMultiByte(CP_UTF8, 0, wide_str.data(), wide_len, &utf8_str[0],
                      utf8_len, nullptr, nullptr);

  return std::string(utf8_str.begin(), utf8_str.end());
}

// std::string gbk_to_utf8(std::string gbkStr) {
//   std::string outUtf8 = "";
//   int n = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, NULL, 0);
//   WCHAR *str1 = new WCHAR[n];
//   MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, str1, n);
//   n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
//   char *str2 = new char[n];
//   WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
//   outUtf8 = str2;
//   delete[] str1;
//   str1 = NULL;
//   delete[] str2;
//   str2 = NULL;
//   return outUtf8;
// }

// std::string convert_gbk_to_utf8(const std::string &gbk_str) {
//   iconv_t cd = iconv_open("UTF-8", "GBK");
//   if (cd == (iconv_t)-1) {
//     perror("iconv_open");
//     return "";
//   }

//   std::string utf8_str;
//   size_t in_left = gbk_str.size();
//   char *in_buf = const_cast<char *>(gbk_str.data());

//   // Allocate a buffer for the converted string
//   size_t out_left = in_left * 4; // Assuming the worst case, each character
//   takes up to 4 bytes in UTF-8 std::vector<char> out_buf(out_left); char
//   *out_ptr = out_buf.data();

//   size_t result = iconv(cd, &in_buf, &in_left, &out_ptr, &out_left);
//   if (result == (size_t)-1) {
//     perror("iconv");
//     iconv_close(cd);
//     return "";
//   }

//   utf8_str.assign(out_buf.data(), out_buf.size() - out_left);

//   iconv_close(cd);
//   return utf8_str;
// }

// 将字符串中的CRLF（\r\n）转换为LF（\n）
std::string convert_crlf_to_lf(const std::string &input) {
  std::string output;
  output.reserve(input.size());

  for (size_t i = 0; i < input.size();) {
    if (input[i] == '\r' && i + 1 < input.size() && input[i + 1] == '\n') {
      output.push_back('\n');
      i += 2; // Skip both '\r' and '\n'
    } else {
      output.push_back(input[i]);
      ++i;
    }
  }

  return output;
}

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

int main(int argc, char **argv) {
  std::string command;
  std::string logDir;
  bool support_utf8 = check_utf8_support();

  parse_arguments(argc, argv, command, logDir);

  // Remove command and its arguments external quotes, if any
  command.erase(std::remove(command.begin(), command.end(), '\"'),
                command.end());

  if (!support_utf8) {
    // Convert command from GBK to UTF8
    command = gbk_to_utf8(command);
  }

  // Get the current date and time
  auto currentTime = std::chrono::system_clock::now();
  std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
  char buffer[26];
  ctime_s(buffer, sizeof(buffer), &currentTimeT);
  std::string currentTimeStr(buffer);
  currentTimeStr.erase(currentTimeStr.find_last_not_of("\n\r") +
                       1); // Remove trailing newline

  bool is_gtest = false;
  if (command.find("-gtest_color=no") != std::string::npos) {
    // Replace -gtest_color=no with -gtest_color=yes
    std::size_t pos = command.find("-gtest_color=no");
    command.replace(pos, 15, "-gtest_color=yes");
    is_gtest = true;
  }

  // Write current time and command to command.txt
  std::string code = support_utf8 ? "UTF-8" : "GBK to UTF-8";
  std::ofstream cmdFile(logDir + "/command.txt", std::ios_base::app);
  cmdFile << "Time: " << currentTimeStr << ", Code: " << code
          << ", Command: " << command << std::endl;
  cmdFile.close();

  // Execute the command and capture the output with colors
  std::string output;
  if (support_utf8) {
    output = exec_and_capture(command.c_str(), logDir);
  } else {
    if (is_gtest) {
      output = exec_powershell_with_file(command.c_str());
    } else {
      output = exec_powershell(command.c_str());
    }
  }

  // Write output to the appropriate log file
  std::string logPath = logDir + "/";
  if (is_gtest) {
    logPath += "gtest.log";
    // Remove the first two lines
    removeFirstTwoLines(output);
  } else {
    logPath += "output.log";
  }
  std::ofstream logFile(logPath, std::ios_base::trunc);

  // Convert CRLF to LF
  if (!support_utf8) {
    output = convert_crlf_to_lf(output);
  }

  // Convert output from UTF-8 to GBK before writing to log file
  logFile << output;
  logFile.close();

  // Limit the lines of the files
  limit_file_lines(logDir + "/command.txt", 2000);
  if (!is_gtest) {
    limit_file_lines(logPath, 5000);
  } else {
    // Display the output to the screen without color
    output =
        std::regex_replace(output, std::regex("\\x1B\\[[0-?]*[ -/]*[@-~]"), "");
  }

  std::cout << output;

  return 0;
}
