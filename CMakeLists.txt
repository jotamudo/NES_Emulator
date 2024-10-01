cmake_minimum_required(VERSION 3.20)

project(
  NintendoEmulator
  LANGUAGES C
  VERSION 0.1 
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
add_subdirectory(ext)

set(
  MAIN_SOURCES
  ./src/opcodes.c
)

add_library(nes_backend STATIC ${MAIN_SOURCES})
target_include_directories(nes_backend PUBLIC ./src/)

add_executable(nes_emu src/nes_emu.c)
target_link_libraries(nes_emu nes_backend)

string(APPEND CMAKE_C_FLAGS_DEBUG " -O0 -ggdb -Wall -Werror -Wall -Wextra -Werror -Wswitch-default -Winvalid-pch -Wodr")

string(APPEND CMAKE_C_FLAGS_RELEASE " -O3")

# unit testing
include(CTest)
set(UNITY_EXTENSION_FIXTURE on)
set(UNITY_EXTENSION_MEMORY on)
add_executable(basic ./test/basic_assert.c)
target_link_libraries(basic nes_backend unity)

add_test(NAME basic_assert COMMAND basic)
