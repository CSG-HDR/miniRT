#!/bin/sh

set -e

find data -name "*.out.txt" | sed s/\\.out\\.txt\$// | sort | cut -c 6- | while IFS= read -r line
do
  if LLVM_PROFILE_FILE=".cache/$line.profraw" xargs -L1 .cache/test.exe < "data/$line.in.txt" | cmp -s - "data/$line.out.txt" ; then
    if [ "$V" = "1" ] || [ "$V" = "2" ] || [ "$V" = "3" ]; then
      if [ -t 1 ]; then
        printf "\033[0;32m[PASS]\033[0m "
      else
        printf "[PASS] "
      fi
      printf "$1 - %s\n" "$line"
    fi
  else
    if [ "$V" = "1" ] || [ "$V" = "2" ] || [ "$V" = "3" ]; then
      if [ -t 1 ]; then
        printf "\033[0;31m[FAIL]\033[0m "
      else
        printf "[FAIL] "
      fi
      printf "$1 - %s\n" "$line"
    fi
    exit 1
  fi
done

if [ "$WITH_COVERAGE" = "1" ]; then
  "$PATH_TO_LLVM_BIN/llvm-profdata" merge -sparse .cache/*.profraw -o .cache/test.profdata
fi
