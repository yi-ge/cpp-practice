include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)

  # ExternalProject_Get_Property(googletest source_dir)
  # set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
  # set(GMOCK_INCLUDE_DIRS ${source_dir}/googlemock/include)
  # file(MAKE_DIRECTORY ${GTEST_INCLUDE_DIRS})
  # file(MAKE_DIRECTORY ${GMOCK_INCLUDE_DIRS})

  # ExternalProject_Get_Property(googletest binary_dir)
  # set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
  # set(GTEST_LIBRARY gtest)
  # add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
  # set_target_properties(${GTEST_LIBRARY} PROPERTIES
  #     "IMPORTED_LOCATION" "${GTEST_LIBRARY_PATH}"
  #     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  #     "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}")
  # add_dependencies(${GTEST_LIBRARY} googletest)

  # set(GTEST_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a)
  # set(GTEST_MAIN_LIBRARY gtest_main)
  # add_library(${GTEST_MAIN_LIBRARY} UNKNOWN IMPORTED)
  # set_target_properties(${GTEST_MAIN_LIBRARY} PROPERTIES
  #     "IMPORTED_LOCATION" "${GTEST_MAIN_LIBRARY_PATH}"
  #     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  #     "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}")
  # add_dependencies(${GTEST_MAIN_LIBRARY} googletest)

  # set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
  # set(GMOCK_LIBRARY gmock)
  # add_library(${GMOCK_LIBRARY} UNKNOWN IMPORTED)
  # set_target_properties(${GMOCK_LIBRARY} PROPERTIES
  #     "IMPORTED_LOCATION" "${GMOCK_LIBRARY_PATH}"
  #     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  #     "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
  # add_dependencies(${GMOCK_LIBRARY} googletest)

  # set(GMOCK_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main.a)
  # set(GMOCK_MAIN_LIBRARY gmock_main)
  # add_library(${GMOCK_MAIN_LIBRARY} UNKNOWN IMPORTED)
  # set_target_properties(${GMOCK_MAIN_LIBRARY} PROPERTIES
  #     "IMPORTED_LOCATION" "${GMOCK_MAIN_LIBRARY_PATH}"
  #     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  #     "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
  # add_dependencies(${GMOCK_MAIN_LIBRARY} ${GTEST_LIBRARY})

  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

if(WIN32)
    set(GTEST_REPLACE_SRC ${PROJECT_SOURCE_DIR}/scripts/gtest.cc)
    if(EXISTS "${GTEST_REPLACE_SRC}")
        set(GTEST_REPLACE_DEST ${googletest_SOURCE_DIR}/googletest/src/gtest.cc)
        configure_file(${GTEST_REPLACE_SRC} ${GTEST_REPLACE_DEST} COPYONLY)
        message(STATUS "Replaced gtest.cc with custom version")
    endif()
endif()
