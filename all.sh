#!/bin/sh

TARGET=production PROFILE=release PRECISION=3 make -C src
TARGET=production PROFILE=release PRECISION=2 make -C src
TARGET=production PROFILE=release PRECISION=1 make -C src
TARGET=production PROFILE=release PRECISION=0 make -C src
TARGET=production PROFILE=debug PRECISION=3 make -C src
TARGET=production PROFILE=debug PRECISION=2 make -C src
TARGET=production PROFILE=debug PRECISION=1 make -C src
TARGET=production PROFILE=debug PRECISION=0 make -C src
TARGET=development PROFILE=release PRECISION=3 make -C src
TARGET=development PROFILE=release PRECISION=2 make -C src
TARGET=development PROFILE=release PRECISION=1 make -C src
TARGET=development PROFILE=release PRECISION=0 make -C src
TARGET=development PROFILE=debug PRECISION=3 make -C src
TARGET=development PROFILE=debug PRECISION=2 make -C src
TARGET=development PROFILE=debug PRECISION=1 make -C src
TARGET=development PROFILE=debug PRECISION=0 make -C src
TARGET=production PROFILE=release PRECISION=3 SANITIZER=address make -C src
TARGET=production PROFILE=release PRECISION=2 SANITIZER=address make -C src
TARGET=production PROFILE=release PRECISION=1 SANITIZER=address make -C src
TARGET=production PROFILE=release PRECISION=0 SANITIZER=address make -C src
TARGET=production PROFILE=debug PRECISION=3 SANITIZER=address make -C src
TARGET=production PROFILE=debug PRECISION=2 SANITIZER=address make -C src
TARGET=production PROFILE=debug PRECISION=1 SANITIZER=address make -C src
TARGET=production PROFILE=debug PRECISION=0 SANITIZER=address make -C src
TARGET=development PROFILE=release PRECISION=3 SANITIZER=address make -C src
TARGET=development PROFILE=release PRECISION=2 SANITIZER=address make -C src
TARGET=development PROFILE=release PRECISION=1 SANITIZER=address make -C src
TARGET=development PROFILE=release PRECISION=0 SANITIZER=address make -C src
TARGET=development PROFILE=debug PRECISION=3 SANITIZER=address make -C src
TARGET=development PROFILE=debug PRECISION=2 SANITIZER=address make -C src
TARGET=development PROFILE=debug PRECISION=1 SANITIZER=address make -C src
TARGET=development PROFILE=debug PRECISION=0 SANITIZER=address make -C src
TARGET=production PROFILE=release PRECISION=3 SANITIZER=undefined make -C src
TARGET=production PROFILE=release PRECISION=2 SANITIZER=undefined make -C src
TARGET=production PROFILE=release PRECISION=1 SANITIZER=undefined make -C src
TARGET=production PROFILE=release PRECISION=0 SANITIZER=undefined make -C src
TARGET=production PROFILE=debug PRECISION=3 SANITIZER=undefined make -C src
TARGET=production PROFILE=debug PRECISION=2 SANITIZER=undefined make -C src
TARGET=production PROFILE=debug PRECISION=1 SANITIZER=undefined make -C src
TARGET=production PROFILE=debug PRECISION=0 SANITIZER=undefined make -C src
TARGET=development PROFILE=release PRECISION=3 SANITIZER=undefined make -C src
TARGET=development PROFILE=release PRECISION=2 SANITIZER=undefined make -C src
TARGET=development PROFILE=release PRECISION=1 SANITIZER=undefined make -C src
TARGET=development PROFILE=release PRECISION=0 SANITIZER=undefined make -C src
TARGET=development PROFILE=debug PRECISION=3 SANITIZER=undefined make -C src
TARGET=development PROFILE=debug PRECISION=2 SANITIZER=undefined make -C src
TARGET=development PROFILE=debug PRECISION=1 SANITIZER=undefined make -C src
TARGET=development PROFILE=debug PRECISION=0 SANITIZER=undefined make -C src
TARGET=production PROFILE=release PRECISION=3 SANITIZER=memory make -C src
TARGET=production PROFILE=release PRECISION=2 SANITIZER=memory make -C src
TARGET=production PROFILE=release PRECISION=1 SANITIZER=memory make -C src
TARGET=production PROFILE=release PRECISION=0 SANITIZER=memory make -C src
TARGET=production PROFILE=debug PRECISION=3 SANITIZER=memory make -C src
TARGET=production PROFILE=debug PRECISION=2 SANITIZER=memory make -C src
TARGET=production PROFILE=debug PRECISION=1 SANITIZER=memory make -C src
TARGET=production PROFILE=debug PRECISION=0 SANITIZER=memory make -C src
TARGET=development PROFILE=release PRECISION=3 SANITIZER=memory make -C src
TARGET=development PROFILE=release PRECISION=2 SANITIZER=memory make -C src
TARGET=development PROFILE=release PRECISION=1 SANITIZER=memory make -C src
TARGET=development PROFILE=release PRECISION=0 SANITIZER=memory make -C src
TARGET=development PROFILE=debug PRECISION=3 SANITIZER=memory make -C src
TARGET=development PROFILE=debug PRECISION=2 SANITIZER=memory make -C src
TARGET=development PROFILE=debug PRECISION=1 SANITIZER=memory make -C src
TARGET=development PROFILE=debug PRECISION=0 SANITIZER=memory make -C src
TARGET=production PROFILE=release PRECISION=3 SANITIZER=leak make -C src
TARGET=production PROFILE=release PRECISION=2 SANITIZER=leak make -C src
TARGET=production PROFILE=release PRECISION=1 SANITIZER=leak make -C src
TARGET=production PROFILE=release PRECISION=0 SANITIZER=leak make -C src
TARGET=production PROFILE=debug PRECISION=3 SANITIZER=leak make -C src
TARGET=production PROFILE=debug PRECISION=2 SANITIZER=leak make -C src
TARGET=production PROFILE=debug PRECISION=1 SANITIZER=leak make -C src
TARGET=production PROFILE=debug PRECISION=0 SANITIZER=leak make -C src
TARGET=development PROFILE=release PRECISION=3 SANITIZER=leak make -C src
TARGET=development PROFILE=release PRECISION=2 SANITIZER=leak make -C src
TARGET=development PROFILE=release PRECISION=1 SANITIZER=leak make -C src
TARGET=development PROFILE=release PRECISION=0 SANITIZER=leak make -C src
TARGET=development PROFILE=debug PRECISION=3 SANITIZER=leak make -C src
TARGET=development PROFILE=debug PRECISION=2 SANITIZER=leak make -C src
TARGET=development PROFILE=debug PRECISION=1 SANITIZER=leak make -C src
TARGET=development PROFILE=debug PRECISION=0 SANITIZER=leak make -C src
