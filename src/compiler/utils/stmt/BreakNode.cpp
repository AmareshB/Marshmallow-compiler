//
// Created by bsampat5 on 4/13/2018.
//

#include "BreakNode.h"

BreakNode::BreakNode(const std::string &name) : name(name) {}

std::ostream &operator<<(std::ostream &os, const BreakNode &node) {
    os << static_cast<const StatementNode &>(node) << " name: " << node.name;
    return os;
}
