//
// Created by bsampat5 on 4/13/2018.
//

#include "BranchNode.h"



std::string BranchNode::getType() {
    return name;
}

BranchNode::BranchNode( std::string &name, Node *condition, Node *bodyBlock, Node *branch) : name(name),
                                                                                                  condition(condition),
                                                                                                  bodyBlock(bodyBlock),
                                                                                                  branch(branch) {}

