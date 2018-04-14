//
// Created by bsampat5 on 4/13/2018.
//

#include "ProgramNode.h"

ProgramNode::ProgramNode( std::string &name, std::vector<Node> &childStmt) : name(name),
                                                                                        childStmt(childStmt) {}

std::ostream &operator<<(std::ostream &os, const ProgramNode &node) {
    os << static_cast<const Node &>(node) << " name: " << node.name << " childStmt: " << node.childStmt;
    return os;
}
