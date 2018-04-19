//
// Created by bsampat5 on 4/13/2018.
//

#include "WhileNode.h"


std::string WhileNode::getType() {
    return name;
}

WhileNode::WhileNode( std::string &name, Node *expression, Node *block) : name(name), expression(expression),
                                                                               block(block) {}

