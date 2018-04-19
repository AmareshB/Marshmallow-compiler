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
public:
    std::string name;
    std::vector<Node*> childStmt;


    BlockNode( std::string &name,  std::vector<Node*> &childStmt);
    std::string getType();

};

#endif //SER502_SPRING2018_TEAM15_BLOCKNODE_H
