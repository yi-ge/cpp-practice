#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace fs = std::filesystem;

std::string exec_and_capture(const std::string &cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&_pclose)> pipe(
      _popen((cmd + " 2>&1").c_str(), "r"), _pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " -c <command> -l <log path>"
              << std::endl;
    return 1;
  }

  std::string command;
  fs::path logDir;
  std::string logFile;
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-c" && i + 1 < argc) {
      command = argv[++i];
      // 在此处移除命令及其参数的外部引号（如有），注意，仅适用于没有空格的文件名和路径，否则仍然需要用双引号来处理带有空格的路径。
      command.erase(std::remove(command.begin(), command.end(), '\"'),
                    command.end());
      // Replace -gtest_color=no with -gtest_color=yes
      if (command.find("-gtest_color=no") != std::string::npos) {
        command = std::regex_replace(command, std::regex("-gtest_color=no"),
                                     "-gtest_color=yes");
        logFile = "gtest.log";
      } else {
        logFile = "output.log";
      }
    } else if (std::string(argv[i]) == "-l" && i + 1 < argc) {
      logDir = fs::path(argv[++i]);
    }
  }

  if (command.empty() || logDir.empty()) {
    std::cerr << "Both command and log directory are required." << std::endl;
    return 1;
  }

  std::string output = exec_and_capture(command);
  fs::path logPath = logDir / logFile;
  fs::create_directories(logPath.parent_path());
  std::ofstream outFile(logPath, std::ios_base::out | std::ios_base::app);
  if (outFile.is_open()) {
    outFile << output;
    outFile.close();
  } else {
    std::cerr << "Unable to open the output file." << std::endl;
    return 1;
  }

  // ANSI escape codes start with '\x1B'
  std::regex ansi_regex("\x1B\\[[0-9;]*[mK]");
  std::string stripped_output = std::regex_replace(output, ansi_regex, "");
  std::cout << stripped_output;

  return 0;
}
