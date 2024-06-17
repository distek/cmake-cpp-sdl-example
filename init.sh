#!/bin/bash

vcpkg install
cmake -G Ninja -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake ./
echo "cd build"
echo "ninja && ./something"
