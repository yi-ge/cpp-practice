#!/bin/bash

# 清除已有的覆盖率数据
echo "清除已有的覆盖率数据"
lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -z -d build
