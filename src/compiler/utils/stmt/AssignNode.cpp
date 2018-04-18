//
// Created by bsampat5 on 4/13/2018.
//

#include "AssignNode.h"

std::string AssignNode::getType() {
    return "assign";
}

AssignNode::AssignNode(std::string &name, Node *lhs, Node *rhs) : name(name), lhs(lhs), rhs(rhs) {}



