//
// Created by bsampat5 on 4/13/2018.
//

#include "ContinueNode.h"

ContinueNode::ContinueNode(const std::string &name) : name(name) {}

std::ostream &operator<<(std::ostream &os, const ContinueNode &node) {
    os << static_cast<const StatementNode &>(node) << " name: " << node.name;
    return os;
}
