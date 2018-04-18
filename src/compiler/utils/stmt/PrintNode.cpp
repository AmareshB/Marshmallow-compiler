//
// Created by bsampat5 on 4/13/2018.
//

#include "PrintNode.h"

std::string PrintNode::getType() {
    return name;
}

PrintNode::PrintNode( std::string &name, Node *child) : name(name), child(child) {}


