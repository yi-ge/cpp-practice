// 仅适用于Windows的脚本，用于执行命令并捕获输出(输出到日志时保留ANSI转义序列[颜色信息]，输出到终端移除颜色)。
// clang++ -std=c++17 -lAdvapi32 -o .\executionWrapper.exe
// .\executionWrapper.cpp
#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
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

// Function to execute a command and capture the output
std::string exec_and_capture(const char *cmd) {
  std::array<char, 128> buffer;
  std::string result;
  FILE *pipe = _popen(cmd, "r");

  if (!pipe) {
    throw std::runtime_error("_popen() failed!");
  }

  while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
    result += buffer.data();
  }

  int exitStatus = _pclose(pipe);
  if (exitStatus != 0) {
    throw std::runtime_error("Command exited with non-zero status.");
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

int main(int argc, char **argv) {
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
  std::string output = exec_and_capture(command.c_str());

  // Write output to the appropriate log file
  std::string logPath = logDir + "/";
  if (is_gtest) {
    logPath += "gtest.log";
  } else {
    logPath += "output.log";
  }
  std::ofstream logFile(logPath, std::ios_base::trunc);
  logFile << output;
  logFile.close();

  // Limit the lines of the files
  limit_file_lines(logDir + "/command.txt", 2000);
  if (!is_gtest) {
    limit_file_lines(logPath, 5000);
  }

  // Display the output to the screen without color
  std::string output_without_color =
      std::regex_replace(output, std::regex("\\x1B\\[[0-?]*[ -/]*[@-~]"), "");

  if (check_utf8_support()) {
    std::cout << output_without_color;
  } else {
    std::cout << utf8_to_gbk(output_without_color);
  }

  return 0;
}
