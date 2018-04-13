cmake_minimum_required(VERSION 3.10)
project(SER502_Spring2018_Team15)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(SER502_Spring2018_Team15
        src/bytecode.h src/runtime.cpp src/runtime_test.cpp src/runtime.h src/compiler/parser.cpp src/compiler/parser_test.cpp src/compiler/utils/other_nodes/Node.cpp src/compiler/utils/other_nodes/ExpNode.cpp src/compiler/utils/other_nodes/ExpNode.h src/compiler/utils/other_nodes/Node.h src/compiler/utils/other_nodes/IdenNode.cpp src/compiler/utils/other_nodes/IdenNode.h src/compiler/utils/other_nodes/NumberNode.cpp src/compiler/utils/other_nodes/NumberNode.h src/compiler/utils/other_nodes/ParametersNode.cpp src/compiler/utils/other_nodes/ParametersNode.h src/compiler/utils/other_nodes/ProgramNode.cpp src/compiler/utils/other_nodes/ProgramNode.h src/compiler/utils/other_nodes/UnaryNode.cpp src/compiler/utils/other_nodes/UnaryNode.h src/compiler/utils/other_nodes/Block.cpp src/compiler/utils/other_nodes/Block.h src/compiler/utils/other_nodes/BinaryNode.cpp src/compiler/utils/other_nodes/BinaryNode.h src/compiler/utils/other_nodes/ArgumentsNode.cpp src/compiler/utils/other_nodes/ArgumentsNode.h)