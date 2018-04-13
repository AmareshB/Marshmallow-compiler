//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BRANCHNODE_H
#define SER502_SPRING2018_TEAM15_BRANCHNODE_H


#include <string>
#include <compiler/utils/other_nodes/Node.h>
#include <ostream>
#include "StatementNode.h"

class BranchNode : public StatementNode{
    std::string name;
    Node condition;
    Node bodyBlock;
    Node branch;

public:
    BranchNode(const std::string &name, const Node &condition, const Node &bodyBlock, const Node &branch);

    friend std::ostream &operator<<(std::ostream &os, const BranchNode &node);
};


#endif //SER502_SPRING2018_TEAM15_BRANCHNODE_H
