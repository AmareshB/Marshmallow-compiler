//
// Created by bsampat5 on 4/13/2018.
//

#include "Block.h"

Block::Block(const std::string &name, const std::vector<Node> &childStmt) : name(name), childStmt(childStmt) {}

std::ostream &operator<<(std::ostream &os, const Block &block) {
    os << static_cast<const Node &>(block) << " name: " << block.name << " childStmt: " << block.childStmt;
    return os;
}
