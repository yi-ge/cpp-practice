#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif

#include <string>
#include <vector>

std::string exec(const char *cmd) {
#ifdef _WIN32
  DWORD dwMode;
  HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleMode(hOutput, &dwMode);
  dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOutput, dwMode);
#endif

  SECURITY_ATTRIBUTES sa;
  sa.nLength = sizeof(sa);
  sa.lpSecurityDescriptor = NULL;
  sa.bInheritHandle = TRUE;

  HANDLE hRead, hWrite;

  if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
    throw std::runtime_error("CreatePipe failed");
  }

  STARTUPINFO si;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
  si.hStdOutput = hWrite;
  si.hStdError = hWrite;

  PROCESS_INFORMATION pi;
  ZeroMemory(&pi, sizeof(pi));

  if (!CreateProcess(NULL, (LPSTR)cmd, NULL, NULL, TRUE, 0, NULL, NULL, &si,
                     &pi)) {
    CloseHandle(hWrite);
    CloseHandle(hRead);
    throw std::runtime_error("CreateProcess failed");
  }

  CloseHandle(hWrite);

  std::vector<char> buffer(4096);
  DWORD bytesRead;
  std::string output;

  while (true) {
    if (!ReadFile(hRead, buffer.data(), buffer.size(), &bytesRead, NULL)) {
      break;
    }
    output.append(buffer.cbegin(), buffer.cbegin() + bytesRead);
  }

  CloseHandle(hRead);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  return output;
}

int main() {
  // Ensure your command generates ANSI color codes
  std::string output = exec("d:\\Project\\cpp-practice\\build\\cpp-practice."
                            "exe --gtest_color=yes 2>&1");
  std::cout << output;
  return 0;
}