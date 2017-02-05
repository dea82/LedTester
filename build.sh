#!/bin/bash
echo AVR Build Script
. /etc/profile.d/modules.sh
module add avr-gcc
module add cmake
mkdir -p build
cd build
cmake -G "Unix Makefiles" ..
make
