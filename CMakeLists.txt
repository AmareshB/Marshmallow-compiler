cmake_minimum_required(VERSION 3.5)
project(SER502_Spring2018_Team15)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(melloc
        src/utils/node.h
        src/utils/node.cpp
        src/utils/opcodes.h
        src/utils/symbolTable.h
        src/utils/treeHelper.h
        src/utils/treeHelper.cpp
        src/compiler/lexer.h
        src/compiler/lexer.cpp
        src/compiler/parser.h
        src/compiler/parser.cpp
        src/compiler/bytecode.h
        src/compiler/bytecode.cpp
        src/runtime/runtime.h
        src/runtime/runtime.cpp
        src/melloc.cpp)

add_executable(mello
        src/utils/opcodes.h
        src/runtime/runtime.h
        src/runtime/runtime.cpp
        src/mello.cpp)

add_executable(parser
        src/utils/node.h
        src/utils/symbolTable.h
        src/utils/treeHelper.h
        src/compiler/parser.h
        src/utils/node.cpp
        src/utils/treeHelper.cpp
        src/compiler/parser.cpp
        src/tests/parser_test.cpp
        )

add_executable(bytecode
        src/utils/node.h
        src/utils/symbolTable.h
        src/utils/treeHelper.h
        src/compiler/parser.h
        src/utils/node.cpp
        src/utils/treeHelper.cpp
        src/compiler/parser.cpp
        src/compiler/bytecode.h
        src/compiler/bytecode.cpp
        src/runtime/runtime.cpp
        src/runtime/runtime.h
        src/tests/bytecode_test.cpp
)