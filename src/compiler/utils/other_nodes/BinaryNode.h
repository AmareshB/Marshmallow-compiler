//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BINARYNODE_H
#define SER502_SPRING2018_TEAM15_BINARYNODE_H


#include <string>
#include <ostream>
#include "ExpNode.h"

class BinaryNode: public ExpNode {
public:
    std::string name;
    Node *lhs,*rhs;

    BinaryNode(const std::string &name, Node *lhs, Node *rhs);

public:

    std::string getType();

};


#endif //SER502_SPRING2018_TEAM15_BINARYNODE_H
