cmake_minimum_required(VERSION 3.14.0)
project(cpp-practice VERSION 0.1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++17 -stdlib=libc++")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

# 加载gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)
include(CTest)

include_directories(include)
include_directories(src)
include_directories(src/tree)
# aux_source_directory(./src DIR_SRC)
# aux_source_directory("./src/string" DIR_SRC_STRING)
# aux_source_directory(./src/array DIR_SRC_ARRAY)
# aux_source_directory(./src/stack DIR_SRC_STACK)
# aux_source_directory(./src/math DIR_SRC_MATH)
# aux_source_directory(./src/heap DIR_SRC_HEAP)
# aux_source_directory(./src/tree DIR_SRC_TREE)
# aux_source_directory(./src/list DIR_SRC_LIST)
# aux_source_directory(./src/graphs DIR_SRC_GRAPHS)
# aux_source_directory(./src/sort DIR_SRC_SORT)
# aux_source_directory(./src/other DIR_SRC_OTHER)
aux_source_directory(./src/lib DIR_SRC_LIB)
# aux_source_directory(./test DIR_TEST)
aux_source_directory("./test/string" DIR_TEST_STRING)
aux_source_directory(./test/array DIR_TEST_ARRAY)
aux_source_directory(./test/stack DIR_TEST_STACK)
aux_source_directory(./test/math DIR_TEST_MATH)
aux_source_directory(./test/heap DIR_TEST_HEAP)
aux_source_directory(./test/tree DIR_TEST_TREE)
aux_source_directory(./test/list DIR_TEST_LIST)
aux_source_directory(./test/graphs DIR_TEST_GRAPHS)
aux_source_directory(./test/sort DIR_TEST_SORT)
aux_source_directory(./test/other DIR_TEST_OTHER)
aux_source_directory(./test/lib DIR_TEST_LIB)

add_executable(
  ${PROJECT_NAME}
  # ${DIR_SRC}
  # ${DIR_SRC_STRING}
  # ${DIR_SRC_ARRAY}
  # ${DIR_SRC_STACK}
  # ${DIR_SRC_MATH}
  # ${DIR_SRC_HEAP}
  # ${DIR_SRC_TREE}
  # ${DIR_SRC_LIST}
  # ${DIR_SRC_GRAPHS}
  # ${DIR_SRC_SORT}
  # ${DIR_SRC_OTHER}
  ${DIR_SRC_LIB}
  # ${DIR_TEST}
  ${DIR_TEST_STRING}
  ${DIR_TEST_ARRAY}
  ${DIR_TEST_STACK}
  ${DIR_TEST_MATH}
  ${DIR_TEST_HEAP}
  ${DIR_TEST_TREE}
  ${DIR_TEST_LIST}
  ${DIR_TEST_GRAPHS}
  ${DIR_TEST_SORT}
  ${DIR_TEST_OTHER}
  ${DIR_TEST_LIB}
)


target_link_libraries(${PROJECT_NAME} gtest_main)
include(CPack)

gtest_discover_tests(${PROJECT_NAME})

message(STATUS "Use gcov for code coverage test.")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -Wall -fprofile-arcs -ftest-coverage")

# 下面两个二者选其一，一个是可执行文件，一个是链接库
# set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  --coverage")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
