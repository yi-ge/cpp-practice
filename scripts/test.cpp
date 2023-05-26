#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>

std::string exec(const char *cmd) {
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

int main() {
  try {
    // Replace "command" with your desired ANI's command
    std::string aniCommand = "d:\\Project\\cpp-practice\\build\\cpp-practice."
                             "exe --gtest_color=yes 2>&1";
    std::string output = exec(aniCommand.c_str());

    // Save output to file
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
      outputFile << output;
      outputFile.close();
      std::cout << "Output saved to file." << std::endl;
    } else {
      std::cout << "Error opening file." << std::endl;
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
