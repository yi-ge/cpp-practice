#!/bin/bash
COVERAGE_FOLDER=coverage
COVERAGE_FILE=lcov.info
REPORT_FOLDER=report

rm -rf ${COVERAGE_FOLDER}
mkdir ${COVERAGE_FOLDER}

uNames=$(uname -s)
osName=${uNames:0:4}

TMP_COVERAGE_FILE=${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp

if [ "$osName" == "Darw" ]; then # Darwin
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
elif [ "$osName" == "Linu" ]; then # Linux
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
elif [ "$osName" == "MING" ]; then # MINGW, windows, git-bash
  lcov --gcov-tool $PWD/scripts/llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${TMP_COVERAGE_FILE}
fi

lcov --remove ${TMP_COVERAGE_FILE} -o ${TMP_COVERAGE_FILE} "*/include/*"
lcov --rc lcov_branch_coverage=1 -e ${TMP_COVERAGE_FILE} "*src*" -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}
# genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FOLDER}/${COVERAGE_FILE} -o ${COVERAGE_FOLDER}/${REPORT_FOLDER}
