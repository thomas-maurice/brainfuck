CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(brainfuck)

SET(VMAJOR 0)
SET(VMINOR 2)
SET(VERSION ${VMAJOR}.${VMINOR})

MESSAGE(STATUS "Building brainfuck interpreter ${VERSION}")

INCLUDE_DIRECTORIES("include/")
CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/include/config.h.cmake ${PROJECT_SOURCE_DIR}/include/config.h)
FILE(
  GLOB_RECURSE
  sources
  include/*.h
  src/*.cpp
)

ADD_EXECUTABLE(
  brainfuck
  ${sources}
)

INSTALL(TARGETS brainfuck DESTINATION bin)
