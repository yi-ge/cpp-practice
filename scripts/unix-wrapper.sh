#!/bin/bash

# 解析命令行参数
while getopts "c:l:" opt; do
  case $opt in
  c)
    command="$OPTARG"
    ;;
  l)
    logDir="$OPTARG"
    ;;
  *)
    echo "Unknown option: -$OPTARG" >&2
    exit 1
    ;;
  esac
done

# 替换 -gtest_color=no 为 -gtest_color=yes，并选择日志文件的名称
if [[ $command == *"-gtest_color=no"* ]]; then
  command=${command//-gtest_color=no/-gtest_color=yes}
  logFile="gtest.log"
else
  logFile="output.log"
fi

# 构造完整的日志路径
logPath="$logDir/$logFile"

# 执行命令并保存结果
output=$(eval "$command")

# 获取当前日期和时间
currentTime=$(date '+%Y-%m-%d %H:%M:%S')

# 写入当前时间和命令到 command.txt，并在行数超过2000行时删除旧的部分
echo "Time: $currentTime, Command: $command" >>"$logDir/command.txt"
if [ $(wc -l <"$logDir/command.txt") -gt 2000 ]; then
  sed -i '1d' "$logDir/command.txt"
fi

if [ "$logFile" == "gtest.log" ]; then
  # 移除前两行
  output="$(echo "$output" | tail -n +3)"
fi

# 输出结果到日志并保留颜色
echo "$output" >"$logPath"

# Limit output.log to 5000 lines, remove the oldest lines if exceeded
if [ "$logFile" == "output.log" ]; then
  if [ $(wc -l <"$logPath") -gt 5000 ]; then
    linesToRemove=$(($(wc -l <"$logPath") - 5000))
    sed -i "1,${linesToRemove}d" "$logPath"
  fi
else
  # 输出结果到屏幕并移除颜色
  if [ "$(uname)" == "Darwin" ]; then
    # MacOS
    output="$(echo "$output" | sed -E "s/\x1B\[[0-9;]*[mK]//g")"
  else
    # Linux
    output="$(echo "$output" | sed -r "s/\x1B\[[0-9;]*[mK]//g")"
  fi
fi

if [ -z "$output" ]; then
  echo "Error: output is empty or not set."
  exit 1
fi

# 输出结果到屏幕
echo "$output" | tee build/gtest_nocolor.log

# echo "$output" | perl -pe 's/\e\[[0-9;]*m//g'
# echo "$output" | perl -pe 's/\x1b\[[0-9;]*m//g'
# echo "$output" | python3 -c "import re, sys; sys.stdout.write(re.sub(r'\x1b\[[0-9;]*[mK]', '', sys.stdin.read()))"
