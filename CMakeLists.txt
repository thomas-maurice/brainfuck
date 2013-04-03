CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(brainfuck)

SET(VMAJOR 0)
SET(VMINOR 2)
SET(VERSION ${VMAJOR}.${VMINOR})

MESSAGE(STATUS "Building brainfuck interpreter ${VERSION}")

INCLUDE_DIRECTORIES("include/" ${PROJECT_BINARY_DIR}/include)
CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/include/config.h.cmake ${PROJECT_BINARY_DIR}/include/config.h)
FILE(
  GLOB_RECURSE
  interpreter_sources
  include/help.h
  include/debug.c
  src/main.cpp
  src/debug.cpp
  src/help.cpp
)

ADD_EXECUTABLE(
   bfindent
   src/bfindent.cpp
)

ADD_EXECUTABLE(
   str2bf
   src/str2bf.cpp
)

ADD_EXECUTABLE(
  brainfuck
  ${interpreter_sources}
)

ADD_EXECUTABLE(
  int2bf
  src/int2bf.cpp
)

INSTALL(TARGETS brainfuck DESTINATION bin)
