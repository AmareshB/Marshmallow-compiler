//
// Created by Balachandar on 25-04-2018.
//

#include "ReturnNode.h"

std::string ReturnNode::getType() {
    return name;
}

ReturnNode::ReturnNode( std::string &name, Node *child) : name(name), child(child) {}