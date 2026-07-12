cmake_minimum_required(VERSION 3.16)

project(Chip8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(Chip8
    src/main.cpp
    src/Screen.cpp
    src/Registers.cpp
    src/Stack.cpp
    src/ProgramCounter.cpp
    src/CPU.cpp
    src/Memory.cpp
)

target_link_libraries(Chip8 PRIVATE raylib)