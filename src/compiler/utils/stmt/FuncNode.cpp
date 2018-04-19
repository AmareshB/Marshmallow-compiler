//
// Created by bsampat5 on 4/13/2018.
//

#include "FuncNode.h"



std::string FuncNode::getType() {
    return name;
}

FuncNode::FuncNode( std::string &name, Node *identifier, Node *parameters, Node *block) : name(name),
                                                                                               parameters(parameters),
                                                                                               block(block),
                                                                                               identifier(identifier) {}


