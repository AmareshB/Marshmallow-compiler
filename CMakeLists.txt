cmake_minimum_required(VERSION 3.10)
project(SER502_Spring2018_Team15)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(SER502_Spring2018_Team15
        src/bytecode.h src/runtime.cpp src/runtime_test.cpp src/runtime.h src/compiler/parser.cpp src/compiler/parser_test.cpp src/compiler/utils/Node.cpp)