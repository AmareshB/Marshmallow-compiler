//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_FUNCNODE_H
#define SER502_SPRING2018_TEAM15_FUNCNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class FuncNode : public StatementNode{

public:
    std::string name;
    Node* parameters;
    Node* block;
    Node* identifier;
    std::string getType();

    FuncNode(std::string &name, Node *identifier, Node *parameters, Node *block);
};


#endif //SER502_SPRING2018_TEAM15_FUNCNODE_H
