cmake_minimum_required(VERSION 3.10)
project(MyNcursesApp C)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(
  runme
  src/String.c
  src/main.c)
target_link_libraries(runme ${CURSES_LIBRARIES})
