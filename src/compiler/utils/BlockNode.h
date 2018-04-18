//
// Created by Balachandar on 13-04-2018.
//
#ifndef SER502_SPRING2018_TEAM15_BLOCKNODE_H
#define SER502_SPRING2018_TEAM15_BLOCKNODE_H

#include <compiler/utils/other_nodes/Node.h>
#include <string>
#include <vector>
#include <ostream>

class BlockNode : public Node{
    std::string name;
    std::vector<Node*> childStmt;

public:
    BlockNode(const std::string &name, const std::vector<Node*> &childStmt);

    friend std::ostream &operator<<(std::ostream &os, const BlockNode &node);

};

#endif //SER502_SPRING2018_TEAM15_BLOCKNODE_H
