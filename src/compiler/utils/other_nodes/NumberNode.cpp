//
// Created by bsampat5 on 4/13/2018.
//

#include "NumberNode.h"

NumberNode::NumberNode(int val) : val(val) {}

std::ostream &operator<<(std::ostream &os, const NumberNode &node) {
    os << static_cast<const ExpNode &>(node) << " val: " << node.val;
    return os;
}
