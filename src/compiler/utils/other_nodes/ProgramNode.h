//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PROGRAMNODE_H
#define SER502_SPRING2018_TEAM15_PROGRAMNODE_H


#include <string>
#include <vector>
#include <ostream>
#include "Node.h"

class ProgramNode : public Node{
    std::string name;
    std::vector<Node> childStmt;
public:
    ProgramNode(std::string &name,std::vector<Node> &childStmt);

    friend std::ostream &operator<<(std::ostream &os, const ProgramNode &node);
};

#endif //SER502_SPRING2018_TEAM15_PROGRAMNODE_H
