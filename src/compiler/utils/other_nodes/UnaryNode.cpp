//
// Created by bsampat5 on 4/13/2018.
//

#include "UnaryNode.h"

UnaryNode::UnaryNode(const std::string &name, const Node &onlyChild) : name(name), onlyChild(onlyChild) {}

std::ostream &operator<<(std::ostream &os, const UnaryNode &node) {
    os << static_cast<const ExpNode &>(node) << " name: " << node.name << " onlyChild: " << node.onlyChild;
    return os;
}
