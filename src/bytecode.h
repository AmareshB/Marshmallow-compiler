//
// Created by Ejaz on 4/12/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BYTECODE_H
#define SER502_SPRING2018_TEAM15_BYTECODE_H

#define PUSH   0
#define POP    1
#define STORE  2
#define LOAD   3
#define ADD    4
#define SUB    5
#define MUL    6
#define DIV    7
#define MOD    8
#define EQ     9
#define NEQ    10
#define LT     11
#define GT     12
#define LTE    13
#define GTE    14
#define NOT    15
#define AND    16
#define OR     17
#define BRF    18
#define BR     19
#define CALL   20
#define RET    21
#define PRINT  22
#define EXIT   23
#define NOOP   24
#define GSTORE 25
#define GLOAD  26


#include <compiler/utils/SymbolTable.h>
#include <compiler/utils/other_nodes/Node.h>

class bytecode {
    SymbolTable* globalSymbolTable;
public:
    SymbolTable *symbolTable;
    bytecode();
    bytecode(SymbolTable *symTable);
    void generateByteCode(Node *node,std::string typeName, std::vector<int> &vec);
    int findIdentifier(std::string name, SymbolTable *st);
};


#endif