//
// Created by Balachandar on 13-04-2018.
//

#include "BlockNode.h"

BlockNode::BlockNode( std::string &name,  std::vector<Node*> &childStmt) : name(name), childStmt(childStmt) {}

std::string BlockNode::getType() {
    return "block";
}

