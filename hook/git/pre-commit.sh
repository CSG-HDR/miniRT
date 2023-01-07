#!/bin/bash

set -e

git diff --cached --name-only --diff-filter=ACM -- \
  '*.c' '*.h' '*.sh' '*.mk' 'Makefile' \
  | xargs -L1 sh hook/scripts/42header-remover.sh
