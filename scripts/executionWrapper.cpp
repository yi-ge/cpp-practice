// 仅适用于Windows的脚本，用于执行命令并捕获输出，同时保留ANSI转义序列（颜色信息）。
// clang++ -std=c++17 -o executionWrapper.exe executionWrapper.cpp
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

// 根据给定的命令执行并捕获输出，同时保留ANSI转义序列（颜色信息）
std::string exec_and_capture(const std::string &cmd) {
  // 获取当前系统的环境变量 PATH
  char *pathBuffer = nullptr;
  size_t pathBufferSize = 0;
  _dupenv_s(&pathBuffer, &pathBufferSize, "PATH");

  if (pathBuffer == nullptr || pathBufferSize == 0) {
    throw std::runtime_error("_dupenv_s() failed!");
  }

  std::string path(pathBuffer);

  // 在 cmd 命令前加上 “SET PATH=<path> &&”
  std::string modifiedCmd = "SET PATH=" + path + " && " + cmd;

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
  // Get the absolute path of the binary file
  fs::path binAbsolutePath = fs::absolute(argv[0]);

  // Get the path to the binary's directory
  fs::path binDirectoryPath = binAbsolutePath.parent_path();

  // Set the working directory to the binary's directory
  fs::current_path(binDirectoryPath);

  // Check for valid arguments count:
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <command> [args...]" << std::endl;
    return 1;
  }

  // Combine command and its arguments:
  std::string cmd;
  for (int i = 1; i < argc; ++i) {
    cmd += argv[i];
    if (i < argc - 1) {
      cmd += " ";
    }
  }

  // 在此处移除命令及其参数的外部引号（如有），注意，仅适用于没有空格的文件名和路径，否则仍然需要用双引号来处理带有空格的路径。
  cmd.erase(remove(cmd.begin(), cmd.end(), '\"'), cmd.end());

  // Execute command and capture output:
  std::string output = exec_and_capture(cmd);

  // Write the output to build/output.log file:
  fs::path outputFile = fs::current_path() / ".." / "build" / "output.log";
  fs::create_directories(outputFile.parent_path());
  std::ofstream logFile(outputFile);
  if (logFile.is_open()) {
    logFile << output;
    logFile.close();
  } else {
    std::cerr << "Error: Unable to open the output file." << std::endl;
    return 1;
  }

  // Print the output to the console:
  std::cout << output;

  return 0;
}
