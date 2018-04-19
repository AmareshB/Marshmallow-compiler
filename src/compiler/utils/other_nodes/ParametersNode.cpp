//
// Created by bsampat5 on 4/13/2018.
//

#include "ParametersNode.h"

ParametersNode::ParametersNode( std::string &name,  std::vector<Node*> &parameters) : name(name),
                                                                                               parameters(parameters) {}

std::string ParametersNode::getType() {
    return name;
}



