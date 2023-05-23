#!/bin/bash

# 解析命令行参数
while getopts "c:" opt; do
  case $opt in
  c)
    command="$OPTARG"
    ;;
  *)
    echo "Unknown option: -$OPTARG" >&2
    exit 1
    ;;
  esac
done

# 执行命令
eval "$command"
