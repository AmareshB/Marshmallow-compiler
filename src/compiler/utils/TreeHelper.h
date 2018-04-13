//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_TREEHELPER_H
#define SER502_SPRING2018_TEAM15_TREEHELPER_H


#include <compiler/utils/other_nodes/Node.h>
#include <string>
#include <vector>
#include "SymbolTable.h"

class TreeHelper {
public:
    static Node makeAST(std::string name,Node lhs, Node rhs);
    static Node makeAST(std::string name, std::vector<Node> nodes);
    static Node makeAST(std::string name, Node exp, Node newNode1, Node newNode2);
    static void generateAddress(int startingAdress, SymbolTable node );
    static void iterateAddress(SymbolTable symbolTable);
};


#endif //SER502_SPRING2018_TEAM15_TREEHELPER_H
