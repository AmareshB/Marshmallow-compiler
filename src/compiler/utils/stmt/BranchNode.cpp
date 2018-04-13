//
// Created by bsampat5 on 4/13/2018.
//

#include "BranchNode.h"

BranchNode::BranchNode(const std::string &name, const Node &condition, const Node &bodyBlock, const Node &branch)
        : name(name), condition(condition), bodyBlock(bodyBlock), branch(branch) {}

std::ostream &operator<<(std::ostream &os, const BranchNode &node) {
    os << "name: " << node.name << " condition: " << node.condition << " bodyBlock: " << node.bodyBlock << " branch: "
       << node.branch;
    return os;
}
