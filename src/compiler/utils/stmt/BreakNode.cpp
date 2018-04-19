//
// Created by bsampat5 on 4/13/2018.
//

#include "BreakNode.h"

BreakNode::BreakNode( std::string &name) : name(name) {}

std::string BreakNode::getType() {
    return name;
}


