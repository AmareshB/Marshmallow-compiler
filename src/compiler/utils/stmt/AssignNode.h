//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_ASSIGNNODE_H
#define SER502_SPRING2018_TEAM15_ASSIGNNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class AssignNode : public StatementNode{

public:
    std::string name;
    Node* lhs;
    Node* rhs;

    AssignNode( std::string &name, Node *lhs, Node *rhs);

    std::string getType();
};


#endif //SER502_SPRING2018_TEAM15_ASSIGNNODE_H
