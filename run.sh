#!/bin/bash

action=$1

case "$action" in
  c)
    cmake -S . -B build && cmake --build build
    ;;
  r)
    ./build/game
    ;;
  cr)
    cmake -S . -B build && cmake --build build && ./build/game
    ;;
  *)
    echo "Usage: ./run.sh [c|r|cr]"
    ;;
esac

