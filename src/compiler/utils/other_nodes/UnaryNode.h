//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_UNARYNODE_H
#define SER502_SPRING2018_TEAM15_UNARYNODE_H


#include <string>
#include <ostream>
#include "ExpNode.h"

class UnaryNode : public ExpNode{


public:
    std::string name;
    Node* onlyChild;

    UnaryNode( std::string &name, Node *onlyChild);

    std::string getType();
};


#endif //SER502_SPRING2018_TEAM15_UNARYNODE_H
