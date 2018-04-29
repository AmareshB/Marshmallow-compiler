//
// Created by Ejaz on 4/12/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BYTECODE_H
#define SER502_SPRING2018_TEAM15_BYTECODE_H

#include "../utils/symbolTable.h"
#include "../utils/node.h"

class bytecode {
    SymbolTable* globalSymbolTable;
public:
    SymbolTable *symbolTable;
    bytecode();
    bytecode(SymbolTable *symTable);
    void generateByteCode(Node *node,std::string typeName, std::vector<int> &vec);
    int findIdentifier(std::string name, SymbolTable *st);
    ~bytecode();
};


#endif