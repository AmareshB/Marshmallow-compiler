//
// Created by bsampat5 on 4/13/2018.
//

#include "ArgumentsNode.h"

ArgumentsNode::ArgumentsNode( std::string &name,  std::vector<Node*> &arguments) : name(name),
                                                                                            arguments(arguments) {}

std::string ArgumentsNode::getType() {
    return name;
}


