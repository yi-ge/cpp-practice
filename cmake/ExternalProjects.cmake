include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  # FetchContent_Populate(googletest)
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  # set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  # add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  FetchContent_MakeAvailable(googletest)
endif()
# target_compile_options(gtest
# 	PRIVATE
# 		-stdlib=libc++
# )
# target_link_libraries(gtest
# 	PRIVATE
# 		c++
# )
