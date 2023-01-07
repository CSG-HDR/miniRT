#!/bin/sh

printf 'BASE_PATH := ../%s\nDEPS_FILE := ../%s\nINCS_FILE := ../%s\ninclude $(BASE_PATH)/build/test_build.mk\nall: test.exe\n\t@:\n' "$1" "$2" "$3" > .cache/Makefile
