# Adds a module to the system.
#
# This code has originally been copied from
# https://stackoverflow.com/a/62499857.
# The usage of the library modules in the system is heavily inspired by the
# same post and the clang modules documentation.

function(add_module name)
    add_custom_target(${name}.pcm
            COMMAND
                ${CMAKE_CXX_COMPILER}
                -std=c++20
                -stdlib=libc++
                # -L /opt/homebrew/opt/llvm/lib
                # -Wl,-rpath,/opt/homebrew/opt/llvm/lib
                -fmodules
                -c
                ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
                -Xclang -emit-module-interface
                -o ${PREBUILT_MODULE_PATH}/${name}.pcm
            )
    add_dependencies(${PROJECT_NAME} ${name}.pcm)
endfunction()
