cmake_minimum_required(VERSION 3.2.2)

project("LedTester" C)

# Try to automatically find avr-gcc
find_program(AVR_CC avr-gcc)
if(NOT AVR_CC)
  message(FATAL_ERROR "Could not find avr-gcc")
endif(NOT AVR_CC)

SET(SRC_PATH "src")
FILE(GLOB SRC_FILES "${SRC_PATH}/*.c")

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_C_COMPILER ${AVR_CC})
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

SET(CSTANDARD "-std=gnu99")
SET(CWARN "-Wall -Wstrict-prototypes")
# TODO Make generic and if debugging target optimization should be?
SET(COPT "-Os -lm -lprintf_flt")
SET(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -fdata-sections")
# TODO Change to generic mcu
SET(CMCU "-mmcu=atmega32")
# TODO Change to generic clock speed 
SET(CDEFS "-DF_CPU=1000000UL")
SET(CFLAGS "${CMCU} ${CSTANDARD} ${CWARN} ${COPT} ${CTUNING} ${CDEFS}")
SET(CMAKE_C_FLAGS ${CFLAGS})

add_executable(CTest ${SRC_FILES} )

message("* ")
message("* Project Name:\t${PROJECT_NAME}")
message("* Project Source Path:\t${SRC_PATH}")
message("* Project Source Files:\t${SRC_FILES}")
message("* ")
