#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os
import sys
import subprocess

cmd = sys.argv[1]
args = sys.argv[2:]

# 执行命令
process = subprocess.Popen([cmd, *args], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

# 获取命令输出和错误信息
stdout, stderr = process.communicate()

# 将输出写入文件
with open("/Users/yige/Project/cpp-practice/output.log", "a") as log_file:
    log_file.write(stdout)
    log_file.write(stderr)

# 在终端上显示输出
sys.stdout.write(stdout)
sys.stderr.write(stderr)
