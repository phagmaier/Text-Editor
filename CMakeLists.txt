# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyOptimizedProject C)

# Set the C standard to use (optional, but good practice)
set(CMAKE_C_STANDARD 99)

# Set maximum compiler optimization flags
set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native -flto -funroll-loops -fomit-frame-pointer")

# For debugging (if needed, this ensures debugging info is included)
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

# Enable Link Time Optimization (LTO)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

# Use the Release configuration for maximum performance
set(CMAKE_BUILD_TYPE Release)

# Find the ncurses library
find_package(Curses REQUIRED)

# Add your source files here
add_executable(
MyOptimizedProgram 
src/Buffer.c
src/Lines.c
src/main.c
)

# Link ncurses library
target_link_libraries(MyOptimizedProgram PRIVATE ${CURSES_LIBRARIES})

# Include ncurses headers
target_include_directories(MyOptimizedProgram PRIVATE ${CURSES_INCLUDE_DIR})

# Print out the final flags used by the compiler
message(STATUS "C Flags: ${CMAKE_C_FLAGS}")
message(STATUS "C Flags Release: ${CMAKE_C_FLAGS_RELEASE}")

