# Require CMake 3.23.0+ to allow C++23.
cmake_minimum_required(VERSION 3.23.0 FATAL_ERROR)
project(cpp-practice VERSION 0.1.0 LANGUAGES CXX)

message(${CMAKE_CXX_COMPILER})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# GoogleTest requires at C++ 14+
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

if (CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
  set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/src/modules)
  # set(module_compile_options
  #   -fmodules
  #   -fbuiltin-module-map
  #   -fimplicit-module-maps
  #   -fprebuilt-module-path=${PREBUILT_MODULE_PATH}
  # )
  if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_link_options("-fuse-ld=lld-14")
  endif()
  add_compile_options(-std=c++20)
  add_compile_options(-fmodules)
  add_compile_options(-stdlib=libc++)
  add_compile_options(-fbuiltin-module-map)
  add_compile_options(-fimplicit-module-maps)
  add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})

  set(CLANG_TIDY "" CACHE FILEPATH "The clang-tidy executable to use")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)

  # FetchContent_MakeAvailable(googletest)

  enable_testing()
  include(CheckCXXCompilerFlag)
  include(ClangModule)
  # include(CodeCoverage)
  include(ExternalProjects)
  include(GoogleTest)
  include(CTest)
  include(CPack)
  # add_code_coverage()

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

  file(GLOB MODULES src/modules/*.cpp)
  file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})

  # target_compile_options(${PROJECT_NAME}
  #   PRIVATE
  #     ${module_compile_options}
  #     ${diagnostic_compile_options}
  # )

  # set_target_properties(${PROJECT_NAME}
  #   PROPERTIES
  #     CXX_CLANG_TIDY "${CLANG_TIDY}"
  # )

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
    ${MODULES}
  )

  target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

  foreach(modfile ${MODULES})
    get_filename_component(barename ${modfile} NAME)
    get_filename_component(barename_we ${barename} NAME_WE)
    add_module(${barename_we} src/modules/${barename})
  endforeach(modfile ${MODULES})

  gtest_discover_tests(${PROJECT_NAME})

  message(STATUS "Use gcov for code coverage test.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -coverage -Wall -fprofile-arcs -ftest-coverage")
else()

  message(STATUS "Only supports LLVM clang++.")

endif()