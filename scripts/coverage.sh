#!/bin/bash
# 使用bash shell执行此脚本

COVERAGE_FOLDER=coverage
COVERAGE_FILE=lcov.info
REPORT_FOLDER=report

# 删除已存在的覆盖率文件夹，然后创建一个新的覆盖率文件夹
rm -rf ${COVERAGE_FOLDER}
mkdir ${COVERAGE_FOLDER}

# 获取操作系统名称并截取前四个字符
uNames=$(uname -s)
osName=${uNames:0:4}

# 删除与当前单元测试无关的.gcda文件
find build -name "*.gcda" -not -path "*flip_columns_for_maximum_number_of_equal_rows*" -exec rm {} \;

# 设置临时覆盖率文件路径
TMP_COVERAGE_FILE=${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp

# 根据操作系统类型执行相应的lcov命令
if [ "$osName" == "Darw" ]; then # Darwin
  echo "Mac"
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
elif [ "$osName" == "Linu" ]; then # Linux
  echo "Linux"
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
elif [ "$osName" == "MING" ]; then # MINGW, windows, git-bash
  echo "Windows"
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
fi

# 从临时覆盖率文件中移除包含目录
echo "从临时覆盖率文件中移除包含目录"
lcov --remove ${TMP_COVERAGE_FILE} -o ${TMP_COVERAGE_FILE} "*/include/*"

# 从临时覆盖率文件中提取src目录下的覆盖率数据，并保存到最终的覆盖率文件
lcov --rc lcov_branch_coverage=1 -e ${TMP_COVERAGE_FILE} "*src*" -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}

# 生成覆盖率报告（注释掉，如需启用，请取消注释）
# genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FOLDER}/${COVERAGE_FILE} -o ${COVERAGE_FOLDER}/${REPORT_FOLDER}
