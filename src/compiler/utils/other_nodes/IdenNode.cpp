//
// Created by bsampat5 on 4/13/2018.
//

#include <string>
#include "IdenNode.h"

IdenNode::IdenNode(const std::string &name) : name(name) {}

std::ostream &operator<<(std::ostream &os, const IdenNode &node) {
    os << static_cast<const ExpNode &>(node) << " name: " << node.name;
    return os;
}
