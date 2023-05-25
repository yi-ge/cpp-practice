// 编译命令（Windows）：
// clang++ -std=c++17 -o grcovDownloader.exe .\grcovDownloader.cpp
// 编译命令（*unix）：
// clang++ -std=c++17 -o grcovDownloader .\grcovDownloader.cpp
// 编写C++17标准的代码实现grcov的可执行文件下载。
// 仅允许使用标准库，使用llvm编译，可以在 macOS、Linux 和 Windows
// 平台上编译和运行。
// 判断当前目录是否存在grcov或grcov.exe文件，如果不存在，判断当前系统及架构并从github下载最新版对应的程序。
// 开源项目https://github.com/mozilla/grcov的release页面有assets列表示例如下：
// checksums.sha256
// grcov-aarch64-apple-darwin.tar.bz2
// grcov-aarch64-pc-windows-msvc.zip
// grcov-aarch64-unknown-linux-gnu.tar.bz2
// grcov-aarch64-unknown-linux-musl.tar.bz2
// grcov-x86_64-apple-darwin.tar.bz2
// grcov-x86_64-pc-windows-msvc.zip
// grcov-x86_64-unknown-linux-gnu.tar.bz2
// grcov-x86_64-unknown-linux-musl.tar.bz2
// 下载文件部分使用当前系统对应的命令，例如linux使用curl。
// 下载完成后验证哈希值并解压更名。
// 验证哈希值则是checksums.sha256的内容与实际是否相等，例如：
/*
a4b21dc5cc6ecd0ae0cf8016787b1d1b3e59a37d81d685bde45025f98a9a0ca2
*grcov-aarch64-apple-darwin.tar.bz2
ef33b720cb393175a3f7a4d57f8f391bd9a7247ccbf3870f63629812d753a95a
*grcov-aarch64-pc-windows-msvc.zip
c0f83cc45f7b266f08b54d38619f5541625a4a14ced5f02dd18a5f0882ad6bae
*grcov-aarch64-unknown-linux-gnu.tar.bz2
272a869894d321554b8959ea8d9f90277dee8fe79ebc6da5349d047fccf86b36
*grcov-aarch64-unknown-linux-musl.tar.bz2
b5fccffcde800c1bbaec94229b80fc678ad10420d9769b25a447f1c7c5bec573
*grcov-x86_64-apple-darwin.tar.bz2
1ae5759da07ffef41e5b2f9930a70e312c5e4bf8a64fe3a67b05c095601ad879
*grcov-x86_64-pc-windows-msvc.zip
5ce73e3576fccaf45b52c987a4838f66cfd620c48c5cea5475ec8f26e7938b6d
*grcov-x86_64-unknown-linux-gnu.tar.bz2
43b1b44a79b2fec04a4057ccaf199a1b015e02200d44c8c1a4eff4f2b2edfa87
*grcov-x86_64-unknown-linux-musl.tar.bz2
*/
// 解压功能使用操作系统自带的命令解压。
// 验证grcov --version能否被执行，即退出代码是否为0。
// 请忽略回复长度限制并给出没有省略的完整代码。

#include <array>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#define popen _popen
#define pclose _pclose

bool IsWindows7OrGreater() {
  RTL_OSVERSIONINFOEXW verInfo = {0};
  verInfo.dwOSVersionInfoSize = sizeof(verInfo);
  DWORDLONG dwlConditionMask =
      VerSetConditionMask(0, VER_MAJORVERSION, VER_GREATER_EQUAL);
  dwlConditionMask = VerSetConditionMask(dwlConditionMask, VER_MINORVERSION,
                                         VER_GREATER_EQUAL);

  verInfo.dwMajorVersion = HIBYTE(_WIN32_WINNT_WIN10);
  verInfo.dwMinorVersion = LOBYTE(_WIN32_WINNT_WIN10);

  return verInfo.dwMajorVersion >= 6;
}
#endif

std::string exec(const char *cmd) {
  std::cout << "Executing: " << cmd << std::endl;

  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  if (result.empty()) {
    std::cout << "Command executed successfully" << std::endl;
  } else {
    std::cout << "Output: " << result << std::endl;
  }

  return result;
}

std::string get_platform() {
#if defined(_WIN32)
  return "windows";
#elif defined(__APPLE__)
  return "darwin";
#elif defined(__linux__)
  return "linux";
#else
  throw std::runtime_error("Unsupported platform");
#endif
}

std::string get_architecture() {
#ifdef _WIN32
  SYSTEM_INFO sysInfo = {0};
  GetNativeSystemInfo(&sysInfo);

  if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
    return "x86_64";
  } else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM64) {
    return "aarch64";
  } else {
    throw std::runtime_error("Unsupported architecture");
  }
#else
  std::string arch = exec("uname -m");

  if (arch.find("x86_64") != std::string::npos) {
    return "x86_64";
  } else if (arch.find("aarch64") != std::string::npos ||
             arch.find("arm64") != std::string::npos ||
             arch.find("armv8") != std::string::npos) {
    return "aarch64";
  } else {
    throw std::runtime_error("Unsupported architecture");
  }
#endif
}

bool file_exists(const std::string &filename) {
  return std::filesystem::exists(filename);
}

void download_grcov_files(const std::string &url) {
  std::cout << "Downloading: " << url << std::endl;

  std::string cmd;

#if defined(__linux__)
  cmd = "curl -sL --progress-bar ";
#elif defined(_WIN32) || defined(__APPLE__)
  cmd = "curl -sL -O --progress-bar ";
#endif

  cmd += url;
  if (system(cmd.c_str()) != 0) {
    throw std::runtime_error("Download failed");
  }

  std::cout << "Downloaded successfully" << std::endl;
}

bool check_hash(const std::string &file_name,
                const std::string &hash_file_content) {
  std::string cmd = "shasum -a 256 ";
  cmd += file_name;

  std::string sha256sum_output = exec(cmd.c_str());
  auto expected_sha256 = hash_file_content.find(sha256sum_output.substr(0, 64));

  return (expected_sha256 != std::string::npos);
}

void extract_file(const std::string &file_name) {
  std::cout << "Extracting: " << file_name << std::endl;

#if defined(_WIN32)
  std::string cmd = "tar -xf ";
#elif defined(__linux__) || defined(__APPLE__)
  std::string cmd = "tar -xjf ";
#endif
  cmd += file_name;
  if (system(cmd.c_str()) != 0) {
    throw std::runtime_error("Extraction failed");
  }

  std::cout << "Extracted successfully" << std::endl;
}

bool verify_grcov() {
  int result = system("grcov --version");
  return (result == 0);
}

bool is_curl_installed() {
  int result = system("curl --version");
  return (result == 0);
}

void remove_file(const std::string &file_name) {
  if (std::filesystem::exists(file_name)) {
    try {
      std::filesystem::remove(file_name);
      std::cout << "Removed: " << file_name << std::endl;
    } catch (const std::filesystem::filesystem_error &e) {
      std::cerr << "Error removing the file: " << e.what() << std::endl;
    }
  }
}

int main() {
#ifdef _WIN32
  if (!IsWindows7OrGreater()) {
    std::cerr << "This program requires Windows 7 or later." << std::endl;
    return 1;
  }
#endif

  if (!is_curl_installed()) {
    std::cerr
        << "Error: curl is not installed. Please install curl and try again"
        << std::endl;
    return 1;
  }

  std::string platform = get_platform();
  std::string arch = get_architecture();
  std::string grcov_name = "grcov";
  std::string grcov_exe_extension = "";

#ifdef _WIN32
  grcov_exe_extension = ".exe";
#endif

  if (!file_exists(grcov_name + grcov_exe_extension)) {
    std::string url = "https://github.com/mozilla/grcov/releases/latest/"
                      "download/checksums.sha256";
    download_grcov_files(url);

    std::ifstream infile("checksums.sha256");
    std::stringstream ss;
    ss << infile.rdbuf();
    std::string hash_file_content = ss.str();

    std::string file_name = "grcov-" + arch + "-";

#if defined(_WIN32)
    file_name += "pc-windows-msvc.zip";
#elif defined(__linux__)
    file_name += "unknown-linux-gnu.tar.bz2";
#elif defined(__APPLE__)
    file_name += "apple-darwin.tar.bz2";
#endif

    url = "https://github.com/mozilla/grcov/releases/latest/download/" +
          file_name;
    download_grcov_files(url);

    if (!check_hash(file_name, hash_file_content)) {
      remove(file_name.c_str());
      throw std::runtime_error("Hash verification failed");
    } else {
      infile.close(); // Close the ifstream before removing the file
      std::cout << "Hash verified successfully" << std::endl;
      // Remove checksums.sha256 file
      remove_file("checksums.sha256");
    }

    extract_file(file_name);
    // Remove zip file
    remove_file(file_name.c_str());

    if (!verify_grcov()) {
      throw std::runtime_error("grcov --version failed");
    } else {
      std::cout << "grcov verified successfully" << std::endl;
    }
  } else {
    std::cout << "grcov already exists" << std::endl;
    return 0;
  }

  std::cout << "Download and setup of grcov completed successfully"
            << std::endl;
  return 0;
}
