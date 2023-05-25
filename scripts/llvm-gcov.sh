#!/bin/bash
uNames=$(uname -s)
osName=${uNames:0:4}

if [ "$osName" == "Darw" ]; then # Darwin
  exec llvm-cov gcov "$@"
elif [ "$osName" == "Linu" ]; then # Linux
  exec llvm-cov-16 gcov "$@"
elif [ "$osName" == "MING" ]; then # MINGW, windows, git-bash
  exec llvm-cov gcov "$@"
fi
