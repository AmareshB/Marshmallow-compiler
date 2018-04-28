//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_TREEHELPER_H
#define SER502_SPRING2018_TEAM15_TREEHELPER_H



#include <string>
#include <vector>
#include "symbolTable.h"

class TreeHelper {

public:
    TreeHelper();

private:
    enum string_value {
        mod,
        div,
        mul,
        minus,
        plus,
        not_equals,
        equals,
        greater_than,
        lesser_than,
        greater_equals,
        lesser_equals,
        _or,
        _and,
        _not,
        assign,
        _print,
        _continue,
        _break,
        _while,
        _callFunc,
        block,
        program,
        parameters,
        arguments,
        _function,
        _else,
        _if,
        _elif,
        _return
    };
     std::map<std::string, string_value> map_values;
public:
     Node* makeAST(std::string name,Node* lhs, Node* rhs);
     Node* makeAST(std::string name, std::vector<Node *>& nodes);
     Node* makeAST(std::string name, Node* exp, Node* newNode1, Node* newNode2);
     void generateAddress(int startingAdress, SymbolTable& node );
     void iterateAddress(SymbolTable& symbolTable);
     void initialise();
};


#endif //SER502_SPRING2018_TEAM15_TREEHELPER_H
