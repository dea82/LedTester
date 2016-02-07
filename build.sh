#!/bin/bash
echo AVR Build Script

mkdir -p build
cd build
cmake -G "Unix Makefiles" ..
make
