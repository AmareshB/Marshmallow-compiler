//
// Created by bsampat5 on 4/13/2018.
//

#include "BinaryNode.h"



std::string BinaryNode::getType() {
    return "binaryNode";
}

BinaryNode::BinaryNode(const std::string &name, Node *lhs, Node *rhs) : name(name), lhs(lhs), rhs(rhs) {}


