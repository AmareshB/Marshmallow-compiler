//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_ASSIGNNODE_H
#define SER502_SPRING2018_TEAM15_ASSIGNNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class AssignNode : public StatementNode{

    std::string name;
    Node lhs;
    Node rhs;

public:
    AssignNode(const std::string &name, const Node &lhs, const Node &rhs);

    friend std::ostream &operator<<(std::ostream &os, const AssignNode &node);
};


#endif //SER502_SPRING2018_TEAM15_ASSIGNNODE_H
