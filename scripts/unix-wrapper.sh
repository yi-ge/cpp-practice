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

# 输出结果到日志并保留颜色
echo "$output" >"$logPath"

# 输出结果到屏幕并移除颜色
if [ "$(uname)" == "Darwin" ]; then
  # MacOS
  echo "$output" | sed -E "s/\x1B\[[0-9;]*[mK]//g"
else
  # Linux
  echo "$output" | sed -r "s/\x1B\[[0-9;]*[mK]//g"
fi
