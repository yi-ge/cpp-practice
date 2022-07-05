cmake_minimum_required(VERSION 3.14.0)
project(cpp-practice VERSION 0.1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

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

# add_executable(cpp-practice src/main.cpp test/main_test.cpp)
add_executable(cpp-practice test/main_test.cpp)
target_link_libraries(cpp-practice gtest_main)

gtest_discover_tests(cpp-practice)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(include)