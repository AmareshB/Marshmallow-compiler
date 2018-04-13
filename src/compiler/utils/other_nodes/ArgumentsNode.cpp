//
// Created by bsampat5 on 4/13/2018.
//

#include "ArgumentsNode.h"

ArgumentsNode::ArgumentsNode(const std::string &name, const std::vector<Node> &arguments) : name(name),
                                                                                            arguments(arguments) {}

std::ostream &operator<<(std::ostream &os, const ArgumentsNode &node) {
    os << static_cast<const ExpNode &>(node) << " name: " << node.name << " arguments: " << node.arguments;
    return os;
}
