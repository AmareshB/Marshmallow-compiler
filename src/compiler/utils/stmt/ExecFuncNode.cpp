//
// Created by bsampat5 on 4/13/2018.
//

#include "ExecFuncNode.h"



std::string ExecFuncNode::getType() {
    return name;
}

ExecFuncNode::ExecFuncNode( std::string &name, Node *funcName, Node *params) : name(name), funcName(funcName),
                                                                                    params(params) {}


