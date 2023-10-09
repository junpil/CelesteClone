#!/bin/bash

libs=-luser32
warnings="-Wno-writable-strings -Wno-format-security"

clang src/main.cpp -o game.exe $libs $warnings