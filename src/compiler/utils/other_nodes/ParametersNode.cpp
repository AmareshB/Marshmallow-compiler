//
// Created by bsampat5 on 4/13/2018.
//

#include "ParametersNode.h"

ParametersNode::ParametersNode(const std::string &name, const std::vector<Node> &parameters) : name(name),
                                                                                               parameters(parameters) {}

std::ostream &operator<<(std::ostream &os, const ParametersNode &node) {
    os << static_cast<const Node &>(node) << " name: " << node.name << " parameters: " << node.parameters;
    return os;
}
