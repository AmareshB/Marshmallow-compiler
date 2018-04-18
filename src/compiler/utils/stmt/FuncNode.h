//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_FUNCNODE_H
#define SER502_SPRING2018_TEAM15_FUNCNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class FuncNode : public StatementNode{

    std::string name;
    Node identifier;
    Node parameters;
    Node block;

public:
    FuncNode(const std::string &name, const Node &identifier, const Node &parameters, const Node &block);

    friend std::ostream &operator<<(std::ostream &os, const FuncNode &node);
};


#endif //SER502_SPRING2018_TEAM15_FUNCNODE_H
