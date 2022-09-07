#!/bin/sh
uNames=`uname -s`
osName=${uNames: 0: 4}

if [ "$osName" == "Darw" ] # Darwin
then
	exec llvm-cov gcov "$@"
elif [ "$osName" == "Linu" ] # Linux
then
	exec llvm-cov-15 gcov "$@"
elif [ "$osName" == "MING" ] # MINGW, windows, git-bash
then
  exec llvm-cov-15 gcov "$@"
fi
