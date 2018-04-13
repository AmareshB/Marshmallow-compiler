//
// Created by bsampat5 on 4/13/2018.
//

#include "AssignNode.h"

AssignNode::AssignNode(const std::string &name, const Node &lhs, const Node &rhs) : name(name), lhs(lhs), rhs(rhs) {}

std::ostream &operator<<(std::ostream &os, const AssignNode &node) {
    os << static_cast<const StatementNode &>(node) << " name: " << node.name << " lhs: " << node.lhs << " rhs: "
       << node.rhs;
    return os;
}
