@echo off

:DetectOS
if "%OS%" == "Windows_NT" (
  set "osName=Win"
) else (
  echo Unsupported platform: %OS%
  exit /b 1
)

:RunLLVMCov
if "%osName%" == "Win" (
  llvm-cov gcov %*
) else (
  echo Unsupported platform: %osName%
  exit /b 1
)
