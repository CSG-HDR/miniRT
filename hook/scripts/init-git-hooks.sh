#!/bin/sh

set -e

FAILED_AT_LEAST_ONCE=0

if [ -d ".git/hooks" ]; then
  cp ./hook/git/pre-commit.sh .git/hooks/pre-commit
  chmod a+x .git/hooks/pre-commit
  echo "Git pre-commit hook initialized successfully."
elif [ -f ".git" ]; then
  echo "[FAILED] .git file found, but no hooks directory" 1>&2
  FAILED_AT_LEAST_ONCE=1
fi

exit $FAILED_AT_LEAST_ONCE
