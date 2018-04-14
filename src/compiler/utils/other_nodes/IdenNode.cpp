//
// Created by bsampat5 on 4/13/2018.
//

#include <string>
#include "IdenNode.h"

IdenNode::IdenNode(const std::string &name) : name(name) {}

const std::string &IdenNode::getName() const {
    return name;
}

void IdenNode::setName(const std::string &name) {
    IdenNode::name = name;
}



