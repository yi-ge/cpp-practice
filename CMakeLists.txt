# Require CMake 3.23.0+ to allow C++23.
cmake_minimum_required(VERSION 3.23.0 FATAL_ERROR)
project(cpp-practice VERSION 0.1.0 LANGUAGES CXX)

message(${CMAKE_SYSTEM_NAME}: ${CMAKE_CXX_COMPILER})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# GoogleTest requires at C++ 14+
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(USE_CUSTOM_LIBC OFF)
# set STDLIB use libstdc++ or libc++
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set(STDLIB libc++)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(STDLIB libstdc++)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
  set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/src/modules)

  if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_link_options("-fuse-ld=lld-14")
  endif()

  add_compile_options(-std=c++20)
  if (USE_CUSTOM_LIBC)
    add_compile_options(-nostdinc++)
    add_compile_options(-nostdlib++)
    if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
      set(LLVM_DIR /opt/homebrew/opt/llvm)
    elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
      set(LLVM_DIR /usr/lib/llvm-14)
    endif()
    add_compile_options(-isystem ${LLVM_DIR}/include/c++/v1)
    add_compile_options(-L ${LLVM_DIR}/lib)
    add_compile_options(-Wl,-rpath,${LLVM_DIR}/lib)
    add_compile_options(-lc++)
  else()
    if (STDLIB STREQUAL "libstdc++")
      add_compile_options(-stdlib=libstdc++)
    else()
      add_compile_options(-stdlib=libc++)
      # add_compile_options(-lc++)
      # add_compile_options(-lc++abi)
    endif()
  endif()
  # 开启module支持
  add_compile_options(-fmodules)
  add_compile_options(-fbuiltin-module-map)
  add_compile_options(-fimplicit-module-maps)
  add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})

  set(CLANG_TIDY "" CACHE FILEPATH "The clang-tidy executable to use")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  set(THREADS_PREFER_PTHREAD_FLAG ON)

  find_package(Threads REQUIRED)

  enable_testing()
  include(CheckCXXCompilerFlag)
  include(ClangModule)
  include(ExternalProjects)
  include(GoogleTest)
  include(CTest)
  include(CPack)

  include_directories(include)
  include_directories(src)
  include_directories(src/tree)

  # find_package(GTest REQUIRED)
  include_directories(${googletest_SOURCE_DIR}/googletest/include)
  include_directories(${googletest_SOURCE_DIR}/googlemock/include)

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
  aux_source_directory(./test/modules DIR_TEST_MODULES)

  file(GLOB MODULES src/modules/*.cpp)
  file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})

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
    # 开启module支持
    ${DIR_TEST_MODULES}
    ${MODULES}
  )

  target_link_libraries(${PROJECT_NAME} Threads::Threads)
  target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

  # 开启module支持
  foreach(modfile ${MODULES})
    get_filename_component(barename ${modfile} NAME)
    get_filename_component(barename_we ${barename} NAME_WE)
    add_module(${barename_we} src/modules/${barename})
  endforeach(modfile ${MODULES})

  gtest_discover_tests(${PROJECT_NAME})

  if(DEFINED ENV{CI})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -Wall -fprofile-arcs -ftest-coverage")
  endif()
else()

  message(STATUS "Only supports LLVM clang++.")

endif()