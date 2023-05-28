// 仅适用于Windows的脚本，用于执行命令并捕获输出(输出到日志时保留ANSI转义序列[颜色信息]，输出到终端移除颜色)。
// clang++ -std=c++17 -lAdvapi32 -o .\executionWrapper.exe
// .\executionWrapper.cpp
#include <algorithm>
#include <array>
#include <chrono>
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

// Function to execute a command and capture the output
// std::string exec_and_capture(const char *cmd, const std::string &logDir) {
//   std::array<char, 128> buffer;
//   std::string result;

//   std::ofstream errorLogFile(logDir + "/command_sys_exec.log",
//                              std::ios_base::app);
//   errorLogFile << "_popen之前" << std::endl;
//   errorLogFile.close();

//   FILE *pipe = _popen(cmd, "r");

//   std::ofstream errorLogFile2(logDir + "/command_sys_exec2.log",
//                               std::ios_base::app);
//   errorLogFile2 << "_popen后" << std::endl;
//   errorLogFile2.close();

//   if (!pipe) {
//     // throw std::runtime_error("_popen() failed!");
//     std::ofstream errorLogFile(logDir + "/command_sys_error.log",
//                                std::ios_base::app);
//     errorLogFile << "_popen() failed!" << std::endl;
//     errorLogFile.close();
//   }

//   while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
//     result += buffer.data();
//   }

//   int exitStatus = _pclose(pipe);

//   // 将命令字符串和输出写入 command_output.log 文件
//   std::ofstream outputLogFile(logDir + "/command_output.log",
//                               std::ios_base::app);
//   outputLogFile << "Command: " << cmd << std::endl;
//   outputLogFile << "Output: " << result << std::endl;
//   outputLogFile.close();

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
std::string exec_and_capture(const char *cmd, const std::string &logDir) {
  constexpr size_t BUFFER_SIZE = 128;
  std::array<char, BUFFER_SIZE> buffer{};
  std::string result;

  // 创建临时文件名以存储命令输出
  std::string temp_file = generate_unique_path();

  // 将命令的输出重定向到临时文件
  std::string modified_cmd = std::string(cmd) + " >" + temp_file + " 2>&1";

  // 使用 std::system 执行命令
  int exitStatus = std::system(modified_cmd.c_str());

  // 读取临时文件的内容
  std::ifstream inputFile(temp_file);
  while (inputFile.getline(buffer.data(), BUFFER_SIZE)) {
    result += buffer.data();
    result += '\n';
  }
  inputFile.close();

  // 删除临时文件
  std::filesystem::remove(temp_file);

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

// 将gbk字符串转换为utf8字符串
std::string gbk_to_utf8(const std::string &gbk_str) {
  int wide_len =
      MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(), -1, nullptr, 0);
  std::wstring wide_str(wide_len - 1,
                        0); // Subtract 1 to exclude null character
  MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(), -1, &wide_str[0], wide_len);

  int utf8_len = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, nullptr,
                                     0, nullptr, nullptr);
  std::string utf8_str(utf8_len - 1, 0); // Subtract 1 to exclude null character
  WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, &utf8_str[0], utf8_len,
                      nullptr, nullptr);

  return utf8_str;
}

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

void convert_argv_to_utf8(int argc, char **&argv) {
  for (int i = 0; i < argc; ++i) {
    std::string gbk_arg(argv[i]);
    std::string utf8_arg = gbk_to_utf8(gbk_arg);
    argv[i] = new char[utf8_arg.size() + 1];
    memcpy(argv[i], utf8_arg.c_str(), utf8_arg.size() + 1);
  }
}

void free_converted_argv(int argc, char **argv) {
  for (int i = 0; i < argc; ++i) {
    delete[] argv[i];
  }
}

int main(int argc, char **argv) {
  if (!check_utf8_support()) {
    // Add this line at the beginning of main to convert arguments from GBK to
    // UTF-8
    convert_argv_to_utf8(argc, argv);
  }

  std::string command;
  std::string logDir;

  parse_arguments(argc, argv, command, logDir);

  // Remove command and its arguments external quotes, if any
  command.erase(std::remove(command.begin(), command.end(), '\"'),
                command.end());

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
  std::ofstream cmdFile(logDir + "/command.txt", std::ios_base::app);
  cmdFile << "Time: " << currentTimeStr << ", Command: " << command
          << std::endl;
  cmdFile.close();

  // Execute the command and capture the output with colors
  std::string output = exec_and_capture(command.c_str(), logDir);

  // Write output to the appropriate log file
  std::string logPath = logDir + "/";
  if (is_gtest) {
    logPath += "gtest.log";
  } else {
    logPath += "output.log";
  }
  std::ofstream logFile(logPath, std::ios_base::trunc);
  // output = convert_crlf_to_lf(output);
  // Convert output from UTF-8 to GBK before writing to log file
  // std::string output_gbk = utf8_to_gbk(output);
  // logFile << output_gbk;
  logFile << output;
  logFile.close();

  // Limit the lines of the files
  limit_file_lines(logDir + "/command.txt", 2000);
  if (!is_gtest) {
    limit_file_lines(logPath, 5000);
  } else {
    // Display the output to the screen without color
    output = std::regex_replace(output, std::regex("\\x1B\\[[0-9;]*[mK]"), "");
  }

  // if (check_utf8_support()) {
  std::cout << output;
  // } else {
  // std::cout << utf8_to_gbk(output);
  // }

  // Free memory allocated for converted arguments
  free_converted_argv(argc, argv);

  return 0;
}
