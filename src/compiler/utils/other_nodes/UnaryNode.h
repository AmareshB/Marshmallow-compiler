//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_UNARYNODE_H
#define SER502_SPRING2018_TEAM15_UNARYNODE_H


#include <string>
#include <ostream>
#include "ExpNode.h"

class UnaryNode : public ExpNode{

    std::string name;
public:
    Node onlyChild;

    UnaryNode(const std::string &name, const Node &onlyChild);

    friend std::ostream &operator<<(std::ostream &os, const UnaryNode &node);
};


#endif //SER502_SPRING2018_TEAM15_UNARYNODE_H
