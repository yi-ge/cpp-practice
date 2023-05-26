// 仅适用于Windows的脚本，用于执行命令并捕获输出，同时保留ANSI转义序列（颜色信息）。
// clang++ -std=c++17 -o executionWrapper.exe executionWrapper.cpp
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace fs = std::filesystem;

std::string exec_and_capture(const std::string &cmd, bool keep_color) {
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
  if (!keep_color) {
    // Remove ANSI color codes
    result =
        std::regex_replace(result, std::regex("\x1B\\[[0-9;]*[a-zA-Z]"), "");
  }
  return result;
}

void trim_file(const fs::path &path, std::size_t max_lines) {
  std::ifstream in(path);
  std::deque<std::string> lines;
  std::string line;
  while (std::getline(in, line)) {
    lines.push_back(line);
    if (lines.size() > max_lines) {
      lines.pop_front();
    }
  }
  in.close();

  std::ofstream out(path);
  for (const auto &l : lines) {
    out << l << '\n';
  }
  out.close();
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
      command.erase(std::remove(command.begin(), command.end(), '\"'),
                    command.end());
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

  // Write command to command.txt
  fs::path cmdPath = logDir / "command.txt";
  std::ofstream cmdFile(cmdPath, std::ios::app);
  std::time_t currentTime = std::time(nullptr);
  cmdFile << std::asctime(std::localtime(&currentTime))
          << "Command: " << command << "\n";
  cmdFile.close();
  trim_file(cmdPath, 2000);

  // Execute command and capture output:
  std::string output = exec_and_capture(command, logFile == "gtest.log");

  // Write the output to file:
  fs::path outputPath = logDir / logFile;
  std::ofstream logFile(outputPath, std::ios::app);
  logFile << output;
  logFile.close();
  trim_file(outputPath, 5000);

  // Print the output to the console (without color codes):
  std::cout << exec_and_capture(command, false);

  return 0;
}
