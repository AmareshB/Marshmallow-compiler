//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_SYMBOLTABLE_H
#define SER502_SPRING2018_TEAM15_SYMBOLTABLE_H


#include <string>
#include <bits/stdc++.h>

class SymbolTable {

public:
    SymbolTable();

    std::unordered_map<std::string,int> symbolTableMap;
    std::vector<SymbolTable *> childMaps;
    SymbolTable* parentMap;
    int startingAddress;
    int endingAddress;

    SymbolTable(const std::unordered_map<std::string, int> &symbolTableMap,
                const std::vector<SymbolTable *> &childMaps);
};


#endif //SER502_SPRING2018_TEAM15_SYMBOLTABLE_H
