//
// Created by bsampat5 on 4/13/2018.
//

#include "BinaryNode.h"

BinaryNode::BinaryNode(const std::string &name, const Node &lhs, const Node &rhs) : name(name), lhs(lhs), rhs(rhs) {}

std::ostream &operator<<(std::ostream &os, const BinaryNode &node) {
    os << static_cast<const ExpNode &>(node) << " name: " << node.name << " lhs: " << node.lhs << " rhs: " << node.rhs;
    return os;
}
