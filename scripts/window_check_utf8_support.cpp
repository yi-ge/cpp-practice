// 检查Windows系统是否开启了“使用 Unicode UTF-8 提供全球语言支持”
// clang++ -std=c++17 -o .\window_check_utf8_support.exe
// .\window_check_utf8_support.cpp -lAdvapi3
#include <iostream>
#include <string>
#include <windows.h>

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

int main() {
  bool utf8_support_enabled = check_utf8_support();

  if (utf8_support_enabled) {
    std::cout << "UTF-8 support is enabled." << std::endl;
  } else {
    std::cout << "UTF-8 support is not enabled." << std::endl;
  }

  return 0;
}
