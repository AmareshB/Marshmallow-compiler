//
// Created by bsampat5 on 4/13/2018.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable(const std::unordered_map<std::string, int> &symbolTableMap,
                         const std::vector<SymbolTable> &childMaps) : symbolTableMap(symbolTableMap),
                                                                      childMaps(childMaps) {}
