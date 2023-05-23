// clang++ -std=c++17 -o executionWrapper.exe executionWrapper.cpp
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
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
