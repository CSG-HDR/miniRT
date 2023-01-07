#!/bin/sh

while IFS= read -r line
do
  printf "%s: %s\n" "$1" "$(basename "$line.o")"
  printf "%s: %s\n" "$(basename "$line.o")" "../$line"
done
