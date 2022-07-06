#!/bin/bash

COVERAGE_FILE=coverage.info
REPORT_FOLDER=coverage_report
PWD=`pwd`
lcov --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FILE}_tmp
lcov --remove ${COVERAGE_FILE}_tmp -o ${COVERAGE_FILE}_tmp "*/include/*"
lcov --rc lcov_branch_coverage=1 -e ${COVERAGE_FILE}_tmp "*src*" -o ${COVERAGE_FILE}
genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FILE} -o ${REPORT_FOLDER}
