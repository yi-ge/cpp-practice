#!/bin/bash
COVERAGE_FOLDER=coverage
COVERAGE_FILE=lcov.info
REPORT_FOLDER=report

rm -rf ${COVERAGE_FOLDER}
mkdir ${COVERAGE_FOLDER}

uNames=`uname -s`
osName=${uNames: 0: 4}
if [ "$osName" == "Darw" ] # Darwin
then
	lcov --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp
elif [ "$osName" == "Linu" ] # Linux
then
	lcov --gcov-tool llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp
elif [ "$osName" == "MING" ] # MINGW, windows, git-bash
then
  lcov --gcov-tool llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp
fi

lcov --gcov-tool llvm-gcov.sh --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp
lcov --remove ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp "*/include/*"
lcov --rc lcov_branch_coverage=1 -e ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp "*src*" -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}
# genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FOLDER}/${COVERAGE_FILE} -o ${COVERAGE_FOLDER}/${REPORT_FOLDER}
