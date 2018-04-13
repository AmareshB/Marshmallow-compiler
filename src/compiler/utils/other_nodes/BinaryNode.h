//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BINARYNODE_H
#define SER502_SPRING2018_TEAM15_BINARYNODE_H


#include <string>
#include <ostream>
#include "ExpNode.h"

class BinaryNode: public ExpNode {
    std::string name;
    Node lhs,rhs;
public:
    BinaryNode(const std::string &name, const Node &lhs, const Node &rhs);

    friend std::ostream &operator<<(std::ostream &os, const BinaryNode &node);
};


#endif //SER502_SPRING2018_TEAM15_BINARYNODE_H
