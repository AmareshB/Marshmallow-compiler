//
// Created by bsampat5 on 4/13/2018.
//

#include "PrintNode.h"

PrintNode::PrintNode(const std::string &name, const Node &child) : name(name), child(child) {}

std::ostream &operator<<(std::ostream &os, const PrintNode &node) {
    os << static_cast<const StatementNode &>(node) << " name: " << node.name << " child: " << node.child;
    return os;
}
