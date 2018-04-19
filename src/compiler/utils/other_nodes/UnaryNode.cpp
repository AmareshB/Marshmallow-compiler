//
// Created by bsampat5 on 4/13/2018.
//

#include "UnaryNode.h"



std::string UnaryNode::getType() {
    return "unary";
}

UnaryNode::UnaryNode(std::string &name, Node *onlyChild) : name(name), onlyChild(onlyChild) {}



