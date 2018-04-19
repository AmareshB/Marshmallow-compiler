//
// Created by bsampat5 on 4/13/2018.
//

#include "ContinueNode.h"

ContinueNode::ContinueNode( std::string &name) : name(name) {}

std::string ContinueNode::getType() {
    return name;
}

