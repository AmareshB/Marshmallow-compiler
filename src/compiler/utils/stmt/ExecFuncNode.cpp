//
// Created by bsampat5 on 4/13/2018.
//

#include "ExecFuncNode.h"

ExecFuncNode::ExecFuncNode(const std::string &name, const Node &funcName, const Node &params) : name(name),
                                                                                                funcName(funcName),
                                                                                                params(params) {}

std::ostream &operator<<(std::ostream &os, const ExecFuncNode &node) {
    os << "name: " << node.name << " funcName: " << node.funcName << " params: " << node.params;
    return os;
}
