//
// Created by bsampat5 on 4/13/2018.
//

#include "WhileNode.h"

WhileNode::WhileNode(const std::string &name, const Node &expression, const Node &block) : name(name),
                                                                                           expression(expression),
                                                                                           block(block) {}

std::ostream &operator<<(std::ostream &os, const WhileNode &node) {
    os << static_cast<const StatementNode &>(node) << " name: " << node.name << " expression: " << node.expression
       << " block: " << node.block;
    return os;
}
