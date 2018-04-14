//
// Created by Balachandar on 13-04-2018.
//

#include "BlockNode.h"

BlockNode::BlockNode(const std::string &name, const std::vector<Node> &childStmt) : name(name), childStmt(childStmt) {}

std::ostream &operator<<(std::ostream &os, const BlockNode &node) {
    os << static_cast<const Node &>(node) << " name: " << node.name << " childStmt: " << node.childStmt;
    return os;
}
