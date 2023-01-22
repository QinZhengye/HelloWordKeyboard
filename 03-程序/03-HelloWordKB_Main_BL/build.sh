#!/bin/bash
if [[ -n "$1" ]]; then
  export BOARD=$1
fi
cmake -B build -G"Ninja"
cmake --build build --config Release
