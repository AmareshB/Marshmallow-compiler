//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_SYMBOLTABLE_H
#define SER502_SPRING2018_TEAM15_SYMBOLTABLE_H


#include <string>
#include "stdc++.h"

class SymbolTable {

public:
    std::unordered_map<std::string,int> symbolTableMap;
    std::unordered_map<std::string, SymbolTable *> childMaps;
    SymbolTable* parentMap;
    int currentAddress=-1;
};

#endif //SER502_SPRING2018_TEAM15_SYMBOLTABLE_H
