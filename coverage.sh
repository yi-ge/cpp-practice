#!/bin/bash
COVERAGE_FOLDER=coverage
COVERAGE_FILE=lcov.info
REPORT_FOLDER=report

mkdir ${COVERAGE_FOLDER}
lcov --rc lcov_branch_coverage=1 -c -d build -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp
lcov --remove ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp "*/include/*"
lcov --rc lcov_branch_coverage=1 -e ${COVERAGE_FOLDER}/${COVERAGE_FILE}_tmp "*src*" -o ${COVERAGE_FOLDER}/${COVERAGE_FILE}
genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FOLDER}/${COVERAGE_FILE} -o ${COVERAGE_FOLDER}/${REPORT_FOLDER}
