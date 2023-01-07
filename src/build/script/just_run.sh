#!/bin/sh

set -e

if LLVM_PROFILE_FILE=".cache/main.profraw" .cache/test.exe ; then
  if [ "$V" = "1" ] || [ "$V" = "2" ] || [ "$V" = "3" ]; then
    if [ -t 1 ]; then
      printf "\033[0;32m[PASS]\033[0m "
    else
      printf "[PASS] "
    fi
    printf "%s\n" "$1"
  fi
else
  if [ "$V" = "1" ] || [ "$V" = "2" ] || [ "$V" = "3" ]; then
    if [ -t 1 ]; then
      printf "\033[0;31m[FAIL]\033[0m "
    else
      printf "[FAIL] "
    fi
    printf "%s\n" "$1"
  fi
  exit 1
fi

if [ "$WITH_COVERAGE" = "1" ]; then
  "$PATH_TO_LLVM_BIN/llvm-profdata" merge -sparse .cache/*.profraw -o .cache/test.profdata
fi
