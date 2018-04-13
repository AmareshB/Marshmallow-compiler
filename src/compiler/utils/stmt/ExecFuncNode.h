//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_EXECFUNCNODE_H
#define SER502_SPRING2018_TEAM15_EXECFUNCNODE_H


#include <string>
#include <compiler/utils/other_nodes/Node.h>
#include <ostream>
#include "StatementNode.h"

class ExecFuncNode : public StatementNode{

    std::string name;
    Node funcName;
    Node params;

public:
    ExecFuncNode(const std::string &name, const Node &funcName, const Node &params);

    friend std::ostream &operator<<(std::ostream &os, const ExecFuncNode &node);

};


#endif //SER502_SPRING2018_TEAM15_EXECFUNCNODE_H
